// File: ecoscore/event/PublicAPI.h
// EcosCore/event/PublicAPI.h
#ifndef ECOSCORE_ECOSCORE_EVENT_PUBLICAPI_H
#define ECOSCORE_ECOSCORE_EVENT_PUBLICAPI_H

#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/event/core/CallbackHandle.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/event/ScopedCallbackHandler.h"

namespace EcosCore::event {

    /**
     * Register a callback with strong typing.
     * Returns a ScopedCallbackHandler managing lifetime.
     */
    template <
        typename EventType,
        typename PhaseTag,
        typename PriorityTag
    >
    ScopedCallbackHandler RegisterCallback(
        core::EventDispatcher& dispatcher,
        const core::EventCallback<EventType, PhaseTag, PriorityTag>& callback)
    {
        return dispatcher.AddCallback<EventType>(callback);
} // namespace EcosCore::event

    /**
     * Dispatch an event for a given phase.
     */
    template <typename EventType, typename PhaseTag>
    void DispatchEvent(core::EventDispatcher& dispatcher, const EventType& event, const PhaseTag& phase) {
        dispatcher.Dispatch(event, phase);
    }

} // namespace EcosCore::event

#endif // ECOSCORE_ECOSCORE_EVENT_PUBLICAPI_H
