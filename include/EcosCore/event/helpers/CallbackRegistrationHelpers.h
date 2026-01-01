// File: ecoscore/event/helpers/CallbackRegistrationHelpers.h
// EcosCore/event/helpers/CallbackRegistrationHelpers.h
#ifndef ECOSCORE_EVENT_HELPERS_CALLBACKREGISTRATIONHELPERS_H
#define ECOSCORE_EVENT_HELPERS_CALLBACKREGISTRATIONHELPERS_H

#include "EcosCore/event/core/CallbackRegistration.h"
#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"

namespace EcosCore::event::helpers {

    /**
     * Helper function to register a callback with default phase and priority.
     */
    template <typename EventT, typename F>
    auto RegisterCallback(EcosCore::event::core::EventDispatcher& dispatcher, F&& cb) {
        return EcosCore::event::core::RegisterCallback<EventT>(
            dispatcher, std::forward<F>(cb),
            EcosCore::tag::Before::instance(),
            EcosCore::tag::Medium::instance());
} // namespace EcosCore::event::helpers

} // namespace EcosCore::event::helpers

#endif // ECOSCORE_EVENT_HELPERS_CALLBACKREGISTRATIONHELPERS_H
