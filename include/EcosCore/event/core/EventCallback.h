// EcosCore/event/core/EventCallback.h
#ifndef ECOSCORE_EVENT_EVENT_CALLBACK_H
#define ECOSCORE_EVENT_EVENT_CALLBACK_H

#include "EcosCore/event/core/Event.h"
#include "EcosCore/state/BaseState.h"
#include "EcosCore/event/core/CallbackResultState.h"
#include "EcosCore/event/core/EventContext.h"

#include <functional>
#include <type_traits>
#include <future>
#include <variant>

namespace ecoscore::event::core {

    struct IEventCallback {
        // Invoke returns either a CallbackResultState or a future of it
        virtual std::variant<const CallbackResultState&, std::future<const CallbackResultState&>> Invoke(const Event&, EventContext&) const = 0;
        virtual const ecoscore::state::BaseState* Priority() const = 0;
        virtual const ecoscore::state::BaseState* Phase() const = 0;
        virtual ~IEventCallback() = default;
    };

    template <typename EventT>
    class EventCallback : public IEventCallback {
    public:
        using CallbackResultRef = const CallbackResultState&;

        // Sync bool callback
        using SyncCallbackBool = std::function<bool(const EventT&, EventContext&)>;
        // Sync void callback
        using SyncCallbackVoid = std::function<void(const EventT&, EventContext&)>;
        // Async callback returning future<CallbackResultRef>
        using AsyncCallback = std::function<std::future<CallbackResultRef>(const EventT&, EventContext&)>;

        // Constructor for sync bool callback
        EventCallback(SyncCallbackBool cb,
            const ecoscore::state::BaseState& phase,
            const ecoscore::state::BaseState& priority)
            : callback_([cb](const EventT& e, EventContext& ctx) -> std::variant<CallbackResultRef, std::future<CallbackResultRef>> {
            return ToCallbackResultState(cb(e, ctx));
                }),
            phase_(&phase), priority_(&priority) {
        }

        // Constructor for sync void callback
        EventCallback(SyncCallbackVoid cb,
            const ecoscore::state::BaseState& phase,
            const ecoscore::state::BaseState& priority)
            : callback_([cb](const EventT& e, EventContext& ctx) -> std::variant<CallbackResultRef, std::future<CallbackResultRef>> {
            cb(e, ctx);
            return Continue::instance();
                }),
            phase_(&phase), priority_(&priority) {
        }

        // Constructor for async callback
        EventCallback(AsyncCallback cb,
            const ecoscore::state::BaseState& phase,
            const ecoscore::state::BaseState& priority)
            : callback_([cb](const EventT& e, EventContext& ctx) -> std::variant<CallbackResultRef, std::future<CallbackResultRef>> {
            return cb(e, ctx);
                }),
            phase_(&phase), priority_(&priority) {
        }

        // Legacy support for void callbacks without EventContext (optional)
        template <typename F,
            typename = std::enable_if_t<
            std::is_invocable_v<F, const EventT&>&&
            std::is_same_v<std::invoke_result_t<F, const EventT&>, void>
            >>
            EventCallback(F&& cb,
                const ecoscore::state::BaseState& phase,
                const ecoscore::state::BaseState& priority)
            : phase_(&phase), priority_(&priority) {
            callback_ = [cb = std::forward<F>(cb)](const EventT& e, EventContext&) -> std::variant<CallbackResultRef, std::future<CallbackResultRef>> {
                cb(e);
                return Continue::instance();
                };
        }

        std::variant<const CallbackResultState&, std::future<const CallbackResultState&>> Invoke(const Event& baseEvent, EventContext& ctx) const override {
            if (auto derived = dynamic_cast<const EventT*>(&baseEvent)) {
                return callback_(*derived, ctx);
            }
            return Continue::instance();
        }

        const ecoscore::state::BaseState* Phase() const override { return phase_; }
        const ecoscore::state::BaseState* Priority() const override { return priority_; }

    private:
        std::function<std::variant<const CallbackResultState&, std::future<const CallbackResultState&>>(const EventT&, EventContext&)> callback_;
        const ecoscore::state::BaseState* phase_;
        const ecoscore::state::BaseState* priority_;
    };

} // namespace ecoscore::event::core

#endif // ECOSCORE_EVENT_EVENT_CALLBACK_H
