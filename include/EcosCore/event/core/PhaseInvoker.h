// EcosCore/event/core/PhaseInvoker.h
#ifndef ECOSCORE_EVENT_CORE_PHASE_INVOKER_H
#define ECOSCORE_EVENT_CORE_PHASE_INVOKER_H

#include <vector>
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/tag/PhaseTags.h"

namespace EcosCore::event::core {

    /**
     * PhaseInvoker:
     * Invokes callbacks registered for a specific phase in order.
     */
    template <typename EventType, typename PhaseTag>
    class PhaseInvoker {
    public:
        using CallbackType = EventCallback<EventType, PhaseTag, EcosCore::tag::Priority>;

        PhaseInvoker() = default;

        explicit PhaseInvoker(std::vector<CallbackType> callbacks)
            : callbacks_(std::move(callbacks)) {
        }

        void AddCallback(CallbackType callback) {
            callbacks_.push_back(std::move(callback));
        }

        void Invoke(const EventType& event, EventContext& ctx) {
            for (const auto& cb : callbacks_) {
                cb(event);
                if (ctx.IsCanceled()) break;
            }
        }

    private:
        std::vector<CallbackType> callbacks_;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_EVENT_CORE_PHASE_INVOKER_H
