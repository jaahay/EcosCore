// EcosCore/event/core/EventContext.h
#ifndef ECOSCORE_EVENT_CORE_EVENT_CONTEXT_H
#define ECOSCORE_EVENT_CORE_EVENT_CONTEXT_H

#include "EcosCore/tag/ResultTags.h"
#include <any>

namespace EcosCore::event::core {

    class EventContext {
    public:
        EventContext() : result_(&EcosCore::tag::Continue::instance()), canceled_(false), skipPhase_(false) {}

        void SetResult(const EcosCore::tag::Result& result) noexcept {
            result_ = &result;
            if (result == EcosCore::tag::Stop::instance()) {
                canceled_ = true;
            }
        }

        const EcosCore::tag::Result& GetResult() const noexcept {
            return *result_;
        }

        void Cancel() noexcept { canceled_ = true; }
        bool IsCanceled() const noexcept { return canceled_; }

        void SkipPhase() noexcept { skipPhase_ = true; }
        bool ShouldSkipPhase() const noexcept { return skipPhase_; }

        void SetUserData(std::any data) { userData_ = std::move(data); }
        const std::any& GetUserData() const { return userData_; }

    private:
        const EcosCore::tag::Result* result_;
        bool canceled_;
        bool skipPhase_;
        std::any userData_;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_EVENT_CORE_EVENT_CONTEXT_H
