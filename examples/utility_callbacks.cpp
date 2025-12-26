#include <iostream>
#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/util/MetricsCallback.h"
#include "EcosCore/event/util/DebugLogger.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/state/BaseState.h"

using namespace ecoscore::event;
using namespace ecoscore::state;

struct UtilityEvent : Event {};

int main() {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<UtilityEvent>(
        util::LoggingCallback<UtilityEvent>(util::DebugLogger::instance()),
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    dispatcher.AddCallback<UtilityEvent>(
        util::MetricsCallback<UtilityEvent>::instance(),
        AfterPhase::instance(),
        DefaultPriority::instance()
    );

    UtilityEvent event;
    dispatcher.Dispatch(event);

    std::cout << "Dispatched UtilityEvent with logging and metrics callbacks.\n";

    return 0;
}
