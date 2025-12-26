#include <iostream>
#include "EcosCore/event/Event.h"
#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/state/DefaultPriorityState.h"

using namespace ecoscore::event;
using namespace ecoscore::event::core;
using namespace ecoscore::event::util;
using namespace ecoscore::state;

struct MyEvent : Event {};

int main() {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<MyEvent>(
        LoggingCallback<MyEvent>::instance(),
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    MyEvent event;
    dispatcher.Dispatch(event);

    std::cout << "Dispatched MyEvent with logging callback.\n";

    return 0;
}
