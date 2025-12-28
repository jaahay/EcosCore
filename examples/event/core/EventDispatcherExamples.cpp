// examples/event/core/EventDispatcherExamples.cpp

#include <iostream>
#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/core/PhaseTagsState.h"
#include "EcosCore/state/DefaultPriorityTags.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/event/util/DebugLogger.h"

using namespace ecoscore::event::core;
using namespace ecoscore::event::util;
using namespace ecoscore::state;

struct SimpleEvent : Event {};

int main() {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<SimpleEvent>(
        LoggingCallback<SimpleEvent>(DebugLogger::instance()),
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    SimpleEvent event;
    dispatcher.Dispatch(event);

    std::cout << "Dispatched SimpleEvent with logging callback.\n";

    return 0;
}
