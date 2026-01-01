// /src/ecoscore/category/category.ixx
export module ecoscore.category.category;

export import ecoscore.category.Category;
export import ecoscore.category.Flows;
export import ecoscore.category.Outcomes;
export import ecoscore.category.Phases;

// Export all flow categorys
export import ecoscore.category.flow.Continue;
export import ecoscore.category.flow.Stop;

// Export all phase categorys
export import ecoscore.category.phase.After;
export import ecoscore.category.phase.Before;
export import ecoscore.category.phase.End;
export import ecoscore.category.phase.Error;
export import ecoscore.category.phase.Finalize;
export import ecoscore.category.phase.Main;
export import ecoscore.category.phase.Process;
export import ecoscore.category.phase.Start;

// Export all outcome categorys
export import ecoscore.category.outcome.Fail;
export import ecoscore.category.outcome.Partial;
export import ecoscore.category.outcome.Pass;

import std;

namespace ecoscore::category {

    /**
     * @brief Facade category domain struct for module identification.
     */
    struct categoryDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.category";
        }
    };

}
