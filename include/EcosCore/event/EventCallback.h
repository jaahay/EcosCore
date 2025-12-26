// EcosCore/event/EventCallback.h
#ifndef ECOSCORE_EVENT_EVENT_CALLBACK_H
#define ECOSCORE_EVENT_EVENT_CALLBACK_H

#include "EcosCore/event/Event.h"
#include "EcosCore/state/BaseState.h"
#include <functional>

namespace ecoscore::event {

    struct IEventCallback {
        virtual bool Invoke(const Event&) const = 0;
        virtual const ecoscore::state::BaseState* Priority() const = 0;
        virtual const ecoscore::state::BaseState* Phase() const = 0;
        virtual ~IEventCallback() = default;
    };

    template <typename EventT>
    class EventCallback : public IEventCallback {
    public:
        using CallbackFunc = std::function<bool(const EventT&)>;

        EventCallback(CallbackFunc cb,
            const ecoscore::state::BaseState& phase,
            const ecoscore::state::BaseState& priority)
            : callback_(std::move(cb)), phase_(&phase), priority_(&priority) {
        }

        bool Invoke(const Event& baseEvent) const override {
            if (auto derived = dynamic_cast<const EventT*>(&baseEvent)) {
                return callback_(*derived);
            }
            return false;
        }

        const ecoscore::state::BaseState* Phase() const override { return phase_; }
        const ecoscore::state::BaseState* Priority() const override { return priority_; }

    private:
        CallbackFunc callback_;
        const ecoscore::state::BaseState* phase_;
        const ecoscore::state::BaseState* priority_;
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_EVENT_CALLBACK_H
