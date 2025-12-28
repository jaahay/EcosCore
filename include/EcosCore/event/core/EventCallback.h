// EcosCore/event/core/EventCallback.h
#ifndef ECOSCORE_EVENT_CORE_EVENT_CALLBACK_H
#define ECOSCORE_EVENT_CORE_EVENT_CALLBACK_H

#include <functional>
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"

namespace EcosCore::event::core {

    /**
     * EventCallback: strongly typed callback with event, phase, and priority tags.
     */
    template <
        typename EventType,
        typename PhaseTag,
        typename PriorityTag
    >
    class EventCallback {
    public:
        using CallbackFunc = std::function<void(const EventType&)>;

        EventCallback(const PhaseTag& phase, const PriorityTag& priority, CallbackFunc cb)
            : phase_(phase), priority_(priority), callback_(std::move(cb)) {
        }

        void operator()(const EventType& event) const {
            callback_(event);
        }

        const PhaseTag& phase() const noexcept { return phase_; }
        const PriorityTag& priority() const noexcept { return priority_; }

    private:
        const PhaseTag& phase_;
        const PriorityTag& priority_;
        CallbackFunc callback_;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_EVENT_CORE_EVENT_CALLBACK_H
