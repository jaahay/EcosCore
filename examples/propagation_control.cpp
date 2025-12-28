// examples/propagation_control.cpp
#include <iostream>
#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/PhaseTagsState.h"
#include "EcosCore/event/CallbackResult.h"
#include "EcosCore/state/BaseType.h"

using namespace ecoscore::event;
using namespace ecoscore::state;

struct MyEvent : Event {};

int main() {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<MyEvent>(
        [](const MyEvent&, EventContext& ctx) {
            std::cout << "First callback runs, stopping propagation.\n";
            ctx.Cancel();
        },
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    dispatcher.AddCallback<MyEvent>(
        [](const MyEvent&, EventContext&) {
            std::cout << "Second callback should NOT run.\n";
        },
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    MyEvent event;
    dispatcher.Dispatch(event);

    return 0;
}
