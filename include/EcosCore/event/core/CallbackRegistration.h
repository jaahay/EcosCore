// EcosCore/event/core/CallbackRegistration.h
#ifndef ECOSCORE_EVENT_CALLBACK_REGISTRATION_H
#define ECOSCORE_EVENT_CALLBACK_REGISTRATION_H

#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/state/BaseState.h"

#include <utility>

namespace ecoscore::event::core {

    // Helper to register a callback with default phase and priority
    template <typename EventT, typename F>
    CallbackHandle RegisterCallback(EventDispatcher& dispatcher, F&& cb,
        const ecoscore::state::BaseState& phase = *MainPhase::instance(),
        const ecoscore::state::BaseState& priority = *DefaultPriority::instance()) {
        return dispatcher.AddCallback<EventT>(std::forward<F>(cb), phase, priority);
    }

    // Helper to register a member function callback with object pointer
    template <typename EventT, typename T, typename F>
    CallbackHandle RegisterMemberCallback(EventDispatcher& dispatcher, T* obj, F&& memFn,
        const ecoscore::state::BaseState& phase = *MainPhase::instance(),
        const ecoscore::state::BaseState& priority = *DefaultPriority::instance()) {
        auto cb = [obj, memFn = std::forward<F>(memFn)](const EventT& e, EventContext& ctx) {
            return (obj->*memFn)(e, ctx);
            };
        return dispatcher.AddCallback<EventT>(std::move(cb), phase, priority);
    }

} // namespace ecoscore::event::core

#endif // ECOSCORE_EVENT_CALLBACK_REGISTRATION_H
