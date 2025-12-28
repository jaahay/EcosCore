// EcosCore/event/core/VirtualEventCallback.h
#ifndef ECOSCORE_EVENT_CORE_VIRTUAL_EVENT_CALLBACK_H
#define ECOSCORE_EVENT_CORE_VIRTUAL_EVENT_CALLBACK_H

#include "EcosCore/event/Event.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/tag/ResultTags.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"
#include <variant>
#include <future>

namespace EcosCore::event::core {

    /**
     * VirtualEventCallback:
     * Interface for event callbacks supporting synchronous and asynchronous invocation.
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

#endif // ECOSCORE_EVENT_CORE_VIRTUAL_EVENT_CALLBACK_H
