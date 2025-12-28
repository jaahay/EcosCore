// examples/event/util/LoggingCallbackExamples.cpp

#include <iostream>
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/event/util/DebugLogger.h"
#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/core/PhaseTagsState.h"
#include "EcosCore/state/DefaultPriorityTags.h"

using namespace ecoscore::event::util;
using namespace ecoscore::event::core;
using namespace ecoscore::state;

struct LogEvent : Event {};

int main() {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<LogEvent>(
        LoggingCallback<LogEvent>(DebugLogger::instance()),
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    LogEvent event;
    dispatcher.Dispatch(event);

    std::cout << "LoggingCallback example complete.\n";

    return 0;
}
