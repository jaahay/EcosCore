// EcosCore/event/EventCallback.h
#ifndef ECOSCORE_EVENT_EVENT_CALLBACK_H
#define ECOSCORE_EVENT_EVENT_CALLBACK_H

#include "EcosCore/event/Event.h"
#include "EcosCore/state/BaseState.h"
#include <functional>
#include <type_traits>

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

        // Constructor for bool-returning callbacks
        EventCallback(CallbackFunc cb,
            const ecoscore::state::BaseState& phase,
            const ecoscore::state::BaseState& priority)
            : callback_(std::move(cb)), phase_(&phase), priority_(&priority) {
        }

        // Constructor for void-returning callbacks (wrapper)
        template <typename F,
            typename = std::enable_if_t<
            std::is_invocable_v<F, const EventT&>&&
            std::is_same_v<std::invoke_result_t<F, const EventT&>, void>
            >>
            EventCallback(F&& cb,
                const ecoscore::state::BaseState& phase,
                const ecoscore::state::BaseState& priority)
            : phase_(&phase), priority_(&priority) {
            callback_ = [cb = std::forward<F>(cb)](const EventT& e) -> bool {
                cb(e);
                return false; // never stop propagation
                };
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
