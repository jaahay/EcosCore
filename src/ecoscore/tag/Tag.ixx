// /src/ecoscore/tag/Tag.ixx
export module ecoscore.tag.Tag;

export import ecoscore.tag.Category;
export import ecoscore.tag.Flows;
export import ecoscore.tag.Outcomes;
export import ecoscore.tag.Phases;

// Export all flow tags
export import ecoscore.tag.flow.Continue;
export import ecoscore.tag.flow.Stop;

// Export all phase tags
export import ecoscore.tag.phase.After;
export import ecoscore.tag.phase.Before;
export import ecoscore.tag.phase.End;
export import ecoscore.tag.phase.Error;
export import ecoscore.tag.phase.Finalize;
export import ecoscore.tag.phase.Main;
export import ecoscore.tag.phase.Process;
export import ecoscore.tag.phase.Start;

// Export all outcome tags
export import ecoscore.tag.outcome.Fail;
export import ecoscore.tag.outcome.Partial;
export import ecoscore.tag.outcome.Pass;

import <string_view>;

namespace ecoscore::tag {

    /**
     * @brief Facade tag domain struct for module identification.
     */
    struct TagDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.tag";
        }
    };

}
