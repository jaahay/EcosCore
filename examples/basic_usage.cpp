#include <iostream>
#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/state/BaseState.h"

using namespace ecoscore::event;
using namespace ecoscore::state;

struct MyEvent : Event {};

int main() {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<MyEvent>(
        util::LoggingCallback<MyEvent>::instance(),
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    MyEvent event;
    dispatcher.Dispatch(event);

    std::cout << "Dispatched MyEvent with logging callback.\n";

    return 0;
}
