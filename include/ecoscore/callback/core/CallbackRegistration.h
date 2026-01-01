// File: ecoscore/callback/core/CallbackRegistration.h
// EcosCore/event/core/CallbackRegistration.h
#ifndef ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKREGISTRATION_H
#define ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKREGISTRATION_H

#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"

#include <utility>

namespace EcosCore::event::core {

    /**
     * Helper to register a callback with default phase and priority.
     */
    template <typename EventT, typename F>
    CallbackHandle RegisterCallback(EventDispatcher& dispatcher, F&& cb,
        const EcosCore::tag::Phase& phase = EcosCore::tag::Before::instance(),
        const EcosCore::tag::Priority& priority = EcosCore::tag::Medium::instance()) {
        return dispatcher.AddCallback<EventT>(std::forward<F>(cb), phase, priority);
} // namespace EcosCore::event::core

    /**
     * Helper to register a member function callback with object pointer.
     */
    template <typename EventT, typename T, typename F>
    CallbackHandle RegisterMemberCallback(EventDispatcher& dispatcher, T* obj, F&& memFn,
        const EcosCore::tag::Phase& phase = EcosCore::tag::Before::instance(),
        const EcosCore::tag::Priority& priority = EcosCore::tag::Medium::instance()) {
        auto cb = [obj, memFn = std::forward<F>(memFn)](const EventT& e, EventContext& ctx) {
            return (obj->*memFn)(e, ctx);
            };
        return dispatcher.AddCallback<EventT>(std::move(cb), phase, priority);
    }

} // namespace EcosCore::event::core

#endif // ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKREGISTRATION_H
