#include <iostream>
#include <future>
#include "EcosCore/event/Event.h"
#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/state/DefaultPriorityTags.h"

using namespace ecoscore::event;
using namespace ecoscore::event::core;
using namespace ecoscore::state;

struct AsyncEvent : Event {};

int main() {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<AsyncEvent>(
        [](const AsyncEvent&, EventContext&) -> std::future<const CallbackResult&> {
            return std::async(std::launch::async, []() -> const CallbackResult& {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << "Async callback executed\n";
                return Continue::instance();
                });
        },
        MainPhase::instance(),
        DefaultPriority::instance()
    );

    AsyncEvent event;
    dispatcher.Dispatch(event);

    std::cout << "Dispatched AsyncEvent with async callback.\n";

    return 0;
}
