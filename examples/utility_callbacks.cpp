#include <iostream>
#include "EcosCore/event/Event.h"
#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/util/MetricsCallback.h"
#include "EcosCore/event/util/DebugLogger.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/state/DefaultPriorityState.h"

using namespace ecoscore::event;
using namespace ecoscore::event::core;
using namespace ecoscore::event::util;
using namespace ecoscore::state;

struct UtilityEvent : Event {};

int main() {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<UtilityEvent>(
        LoggingCallback<UtilityEvent>(DebugLogger::instance()),
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    dispatcher.AddCallback<UtilityEvent>(
        MetricsCallback<UtilityEvent>::instance(),
        AfterPhase::instance(),
        DefaultPriority::instance()
    );

    UtilityEvent event;
    dispatcher.Dispatch(event);

    std::cout << "Dispatched UtilityEvent with logging and metrics callbacks.\n";

    return 0;
}
