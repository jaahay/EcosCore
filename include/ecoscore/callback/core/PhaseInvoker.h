// File: ecoscore/callback/core/PhaseInvoker.h
// EcosCore/event/core/PhaseInvoker.h
#ifndef ECOSCORE_CALLBACK_CORE_PHASEINVOKER_H
#define ECOSCORE_CALLBACK_CORE_PHASEINVOKER_H

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
} // namespace EcosCore::event::core

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

#endif // ECOSCORE_CALLBACK_CORE_PHASEINVOKER_H
