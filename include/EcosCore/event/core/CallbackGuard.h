// EcosCore/event/core/CallbackGuard.h
#ifndef ECOSCORE_EVENT_CALLBACK_GUARD_H
#define ECOSCORE_EVENT_CALLBACK_GUARD_H

#include "EcosCore/event/core/CallbackResultState.h"
#include "EcosCore/event/core/EventContext.h"
#include <functional>

namespace ecoscore::event::core {

    template <typename EventT>
    class CallbackGuard {
    public:
        using CallbackFunc = std::function<const CallbackResultState& (const EventT&, EventContext&)>;

        CallbackGuard(CallbackFunc cb, std::function<bool()> shouldTerminate)
            : callback_(std::move(cb)), shouldTerminate_(std::move(shouldTerminate)) {
        }

        const CallbackResultState& operator()(const EventT& event, EventContext& ctx) const {
            if (shouldTerminate_()) {
                // Early termination
                return Stop::instance();
            }
            return callback_(event, ctx);
        }

    private:
        CallbackFunc callback_;
        std::function<bool()> shouldTerminate_;
    };

} // namespace ecoscore::event::core

#endif // ECOSCORE_EVENT_CALLBACK_GUARD_H
