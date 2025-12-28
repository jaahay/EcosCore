// examples/IntegrationTest.cpp

#include <iostream>
#include <string_view>
#include <vector>

#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/core/EventHierarchy.h"
#include "EcosCore/event/helpers/EventHierarchyHelpers.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/event/util/MetricsCallback.h"
#include "EcosCore/event/util/TimingCallback.h"
#include "EcosCore/event/util/DebugLogger.h"
#include "EcosCore/event/core/CallbackGuard.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/event/util/DefaultFallbackCallbacks.h"
#include "EcosCore/state/BaseType.h"
#include "EcosCore/state/PriorityTags.h"

using namespace ecoscore::event;
using namespace ecoscore::state;
using namespace ecoscore::event::core;
using namespace ecoscore::event::util;

// Define event hierarchy
struct BaseEvent : Event {};
struct DerivedEvent : BaseEvent {};

// Register base events for DerivedEvent
ECOSCORE_REGISTER_BASE_EVENTS(DerivedEvent, BaseEvent)

// Simple priority states
struct HigherPriority : Priority {
    static const HigherPriority& instance() {
        static HigherPriority inst;
        return inst;
    }
    constexpr static constexpr NameSet names() const noexcept { return "HigherPriority"; }
    void print(std::ostream& os) const noexcept override { os << name(); }
};

struct LowerPriority : Priority {
    static const LowerPriority& instance() {
        static LowerPriority inst;
        return inst;
    }
    constexpr static constexpr NameSet names() const noexcept { return "LowerPriority"; }
    void print(std::ostream& os) const noexcept override { os << name(); }
};

int main() {
    EventDispatcher dispatcher;

    // Register fallback interceptor to log when dispatch stops early
    dispatcher.SetFallbackCallback([](const Event& e, const EventContext& ctx) {
        std::cerr << "[Fallback] Dispatch stopped early for event type: " << typeid(e).name() << "\n";
        });

    // Register LoggingCallback for BaseEvent with DebugLogger
    dispatcher.AddCallback<BaseEvent>(
        LoggingCallback<BaseEvent>::instance(),
        BeforePhase::instance(),
        HigherPriority::instance()
    );

    // Register MetricsCallback for BaseEvent
    dispatcher.AddCallback<BaseEvent>(
        MetricsCallback<BaseEvent>::instance(),
        AfterPhase::instance(),
        LowerPriority::instance()
    );

    // Register TimingCallback for DerivedEvent
    dispatcher.AddCallback<DerivedEvent>(
        TimingCallback<DerivedEvent>::instance(),
        AfterPhase::instance(),
        LowerPriority::instance()
    );

    // Register guarded callback for DerivedEvent with cancellation support
    bool cancelFlag = false;
    CallbackGuard<DerivedEvent> guardedCallback(
        [](const DerivedEvent&, EventContext& ctx) {
            std::cout << "Guarded callback executed\n";
            return Continue::instance();
        },
        [&cancelFlag]() { return cancelFlag; }
    );

    dispatcher.AddCallback<DerivedEvent>(
        guardedCallback,
        MainPhase::instance(),
        HigherPriority::instance()
    );

    // Dispatch DerivedEvent - all callbacks should run
    std::cout << "Dispatching DerivedEvent (all callbacks should run):\n";
    DerivedEvent ev;
    dispatcher.Dispatch(ev);

    // Now set cancel flag to true to trigger guarded callback termination
    cancelFlag = true;
    std::cout << "\nDispatching DerivedEvent (guarded callback should terminate early):\n";
    dispatcher.Dispatch(ev);

    return 0;
}
