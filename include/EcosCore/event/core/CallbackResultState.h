// EcosCore/event/core/CallbackResultState.h
#ifndef ECOSCORE_EVENT_CALLBACK_RESULT_STATE_H
#define ECOSCORE_EVENT_CALLBACK_RESULT_STATE_H

#include "EcosCore/state/BaseState.h"
#include "EcosCore/state/TemplateState.h"
#include <string_view>
#include <iostream>

namespace ecoscore::event::core {

    // Base for callback result states
    struct CallbackResultState : ecoscore::state::BaseState {
        virtual ~CallbackResultState() = default;
    };

    // Continue state singleton
    struct Continue : ecoscore::state::TemplateState<Continue, CallbackResultState> {
    private:
        Continue() = default;
    public:
        static const Continue& instance() {
            static Continue inst;
            return inst;
        }
        constexpr std::string_view name() const noexcept { return "Continue"; }
        void print(std::ostream& os) const noexcept override { os << name(); }
    };

    // Stop state singleton
    struct Stop : ecoscore::state::TemplateState<Stop, CallbackResultState> {
    private:
        Stop() = default;
    public:
        static const Stop& instance() {
            static Stop inst;
            return inst;
        }
        constexpr std::string_view name() const noexcept { return "Stop"; }
        void print(std::ostream& os) const noexcept override { os << name(); }
    };

    // Helper to convert bool to CallbackResultState reference
    inline const CallbackResultState& ToCallbackResultState(bool handled) {
        return handled ? ( CallbackResultState&) Stop::instance() : (CallbackResultState&) Continue::instance();
    }

} // namespace ecoscore::event::core

#endif // ECOSCORE_EVENT_CALLBACK_RESULT_STATE_H
