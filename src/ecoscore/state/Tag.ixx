// /src/ecoscore/state/state.ixx
export module ecoscore.state.state;

export import ecoscore.state.Category;
export import ecoscore.state.Flows;
export import ecoscore.state.Outcomes;
export import ecoscore.state.Phases;

// Export all flow states
export import ecoscore.state.flow.Continue;
export import ecoscore.state.flow.Stop;

// Export all phase states
export import ecoscore.state.phase.After;
export import ecoscore.state.phase.Before;
export import ecoscore.state.phase.End;
export import ecoscore.state.phase.Error;
export import ecoscore.state.phase.Finalize;
export import ecoscore.state.phase.Main;
export import ecoscore.state.phase.Process;
export import ecoscore.state.phase.Start;

// Export all outcome states
export import ecoscore.state.outcome.Fail;
export import ecoscore.state.outcome.Partial;
export import ecoscore.state.outcome.Pass;

import std;

namespace ecoscore::state {

    /**
     * @brief Facade state domain struct for module identification.
     */
    struct stateDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.state";
        }
    };

}
