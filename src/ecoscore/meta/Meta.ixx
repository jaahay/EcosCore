// /src/ecoscore/meta/Meta.ixx
export module ecoscore.meta.Meta;

export import ecoscore.meta.CycleCheck;
export import ecoscore.meta.Tuple;
export import ecoscore.meta.TypeList;
export import ecoscore.meta.Variant;

import <string_view>;

namespace ecoscore::meta {

    /**
     * @brief Facade namespace for meta utilities.
     *
     * This module exports all primary meta utilities:
     * - Cycle detection in type dependency graphs.
     * - Tuple concatenation and manipulation.
     * - Variant concatenation and conversion from tuples.
     * - Type list utilities.
     */
    struct MetaTags {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.meta";
        }
    };

}
