// EcosCore/event/core/EventContext.h
#ifndef ECOSCORE_EVENT_EVENT_CONTEXT_H
#define ECOSCORE_EVENT_EVENT_CONTEXT_H

#include "EcosCore/event/CallbackResultState.h"
#include <any>

namespace ecoscore::event {

    class EventContext {
    public:
        EventContext() : result_(&Continue::instance()), canceled_(false), skipPhase_(false) {}

        void SetResult(const CallbackResultState& result) noexcept {
            result_ = &result;
            if (result == Stop::instance()) {
                canceled_ = true;
            }
        }

        const CallbackResultState& GetResult() const noexcept {
            return *result_;
        }

        void Cancel() noexcept { canceled_ = true; }
        bool IsCanceled() const noexcept { return canceled_; }

        void SkipPhase() noexcept { skipPhase_ = true; }
        bool ShouldSkipPhase() const noexcept { return skipPhase_; }

        void SetUserData(std::any data) { userData_ = std::move(data); }
        const std::any& GetUserData() const { return userData_; }

    private:
        const CallbackResultState* result_;
        bool canceled_;
        bool skipPhase_;
        std::any userData_;
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_EVENT_CONTEXT_H
