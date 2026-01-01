// File: ecoscore/callback/VirtualEventCallback.h.h
// EcosCore/event/core/VirtualEventCallback.h
#ifndef ECOSCORE_CALLBACK_VIRTUALEVENTCALLBACK_H_H
#define ECOSCORE_CALLBACK_VIRTUALEVENTCALLBACK_H_H

#include "EcosCore/event/Event.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/tag/ResultTags.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"

#include <variant>
#include <future>

namespace EcosCore::event::core {

    /**
     * VirtualEventCallback: abstract interface for event callbacks.
     * Supports synchronous and asynchronous invocation.
     */
    class VirtualEventCallback {
    public:
        virtual ~VirtualEventCallback() = default;

        virtual std::variant<const EcosCore::tag::Result&, std::future<const EcosCore::tag::Result&>>
            Invoke(const EcosCore::event::Event& event, EventContext& ctx) const = 0;

        virtual const EcosCore::tag::Phase& Phase() const = 0;

        virtual const EcosCore::tag::Priority& Priority() const = 0;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_CALLBACK_VIRTUALEVENTCALLBACK_H_H
