// EcosCore/event/DefaultPriorityState.h
#ifndef ECOSCORE_EVENT_DEFAULT_PRIORITY_STATE_H
#define ECOSCORE_EVENT_DEFAULT_PRIORITY_STATE_H

#include "EcosCore/state/TemplateState.h"
#include "EcosCore/event/PriorityState.h"

namespace ecoscore::event {

    struct DefaultPriority : ecoscore::state::TemplateState<DefaultPriority, PriorityState> {
    private:
        DefaultPriority() = default;
    public:
        static const DefaultPriority& instance() {
            static DefaultPriority inst;
            return inst;
        }
        constexpr std::string_view name() const noexcept { return "DefaultPriority"; }
        void print(std::ostream& os) const noexcept override { os << name(); }
    };

    struct HighPriority : ecoscore::state::TemplateState<HighPriority, PriorityState> {
    private:
        HighPriority() = default;
    public:
        static const HighPriority& instance() {
            static HighPriority inst;
            return inst;
        }
        constexpr std::string_view name() const noexcept { return "HighPriority"; }
        void print(std::ostream& os) const noexcept override { os << name(); }
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_DEFAULT_PRIORITY_STATE_H
