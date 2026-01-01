// File: ecoscore/callback/core/CallbackGuard.h
// EcosCore/event/core/CallbackGuard.h
#ifndef ECOSCORE_CALLBACK_CORE_CALLBACKGUARD_H
#define ECOSCORE_CALLBACK_CORE_CALLBACKGUARD_H

#include "EcosCore/event/core/CallbackResult.h"
#include "EcosCore/event/core/EventContext.h"
#include <functional>

namespace EcosCore::event::core {

    /**
     * CallbackGuard: RAII-style guard to safely invoke callbacks with early termination support.
     */
    template <typename EventT>
    class CallbackGuard {
    public:
        using CallbackFunc = std::function<const CallbackResult& (const EventT&, EventContext&)>;

        CallbackGuard(CallbackFunc cb, std::function<bool()> shouldTerminate)
            : callback_(std::move(cb)), shouldTerminate_(std::move(shouldTerminate)) {
} // namespace EcosCore::event::core

        const CallbackResult& operator()(const EventT& event, EventContext& ctx) const {
            if (shouldTerminate_()) {
                return Stop::instance();
            }
            return callback_(event, ctx);
        }

    private:
        CallbackFunc callback_;
        std::function<bool()> shouldTerminate_;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_CALLBACK_CORE_CALLBACKGUARD_H
