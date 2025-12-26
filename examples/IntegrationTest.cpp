// examples/IntegrationTest.cpp
#include <iostream>
#include <string>
#include <vector>

#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/EventHierarchyHelpers.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/event/util/MetricsCallback.h"
#include "EcosCore/event/util/TimingCallback.h"
#include "EcosCore/event/util/DebugLogger.h"
#include "EcosCore/event/CallbackGuard.h"
#include "EcosCore/event/EventContext.h"
#include "EcosCore/event/DefaultFallbackCallbacks.h"
#include "EcosCore/state/BaseState.h"
#include "EcosCore/state/PriorityState.h"

using namespace ecoscore::event;
using namespace ecoscore::state;
using namespace ecoscore::event::util;

// Define event hierarchy
struct BaseEvent : Event {};
struct DerivedEvent : BaseEvent {};

// Register base events for DerivedEvent
ECOSCORE_REGISTER_BASE_EVENTS(DerivedEvent, BaseEvent)

// Simple priority states
struct HighPriority : PriorityState {
    static const HighPriority& instance() {
        static HighPriority inst;
        return inst;
    }
    constexpr std::string_view name() const noexcept { return "HighPriority"; }
    void print(std::ostream& os) const noexcept override { os << name(); }
};

struct LowPriority : PriorityState {
    static const LowPriority& instance() {
        static LowPriority inst;
        return inst;
    }
    constexpr std::string_view name() const noexcept { return "LowPriority"; }
    void print(std::ostream& os) const noexcept override { os << name(); }
};

int main() {
    EventDispatcher dispatcher;

    // Register fallback interceptor
    dispatcher.SetFallbackCallback([](const Event& e, const EventContext& ctx) {
        std::cerr << "[Fallback] Dispatch stopped early for event type: " << typeid(e).name() << "\n";
        });

    // Register LoggingCallback for BaseEvent with DebugLogger
    dispatcher.AddCallback<BaseEvent>(
        LoggingCallback<BaseEvent>(DebugLogger::instance()),
        BeforePhase::instance(),
        HighPriority::instance()
    );

    // Register MetricsCallback for BaseEvent
    dispatcher.AddCallback<BaseEvent>(
        MetricsCallback<BaseEvent>::instance(),
        AfterPhase::instance(),
        LowPriority::instance()
    );

    // Register TimingCallback for DerivedEvent
    dispatcher.AddCallback<DerivedEvent>(
        TimingCallback<DerivedEvent>::instance(),
        AfterPhase::instance(),
        LowPriority::instance()
    );

    // Register guarded callback for DerivedEvent
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
        HighPriority::instance()
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
