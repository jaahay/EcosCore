// EcosCore/event/CallbackPhaseState.h
#ifndef ECOSCORE_EVENT_CALLBACK_PHASE_STATE_H
#define ECOSCORE_EVENT_CALLBACK_PHASE_STATE_H

#include "EcosCore/state/TemplateState.h"

namespace ecoscore::event {

    struct CallbackPhaseState : ecoscore::state::BaseState {
        virtual ~CallbackPhaseState() = default;
    };

    struct BeforePhase : ecoscore::state::TemplateState<BeforePhase, CallbackPhaseState> {
    private:
        BeforePhase() = default;
    public:
        static const BeforePhase& instance() {
            static BeforePhase inst;
            return inst;
        }
        constexpr std::string_view name() const noexcept { return "Before"; }
        void print(std::ostream& os) const noexcept override { os << name(); }
    };

    struct MainPhase : ecoscore::state::TemplateState<MainPhase, CallbackPhaseState> {
    private:
        MainPhase() = default;
    public:
        static const MainPhase& instance() {
            static MainPhase inst;
            return inst;
        }
        constexpr std::string_view name() const noexcept { return "Main"; }
        void print(std::ostream& os) const noexcept override { os << name(); }
    };

    struct AfterPhase : ecoscore::state::TemplateState<AfterPhase, CallbackPhaseState> {
    private:
        AfterPhase() = default;
    public:
        static const AfterPhase& instance() {
            static AfterPhase inst;
            return inst;
        }
        constexpr std::string_view name() const noexcept { return "After"; }
        void print(std::ostream& os) const noexcept override { os << name(); }
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_CALLBACK_PHASE_STATE_H
