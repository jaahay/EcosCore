// /src/ecoscore/meta/Meta.ixx
#ifndef __SRC_ECOSCORE_META_META_IXX__
#define __SRC_ECOSCORE_META_META_IXX__

#include "ecoscore/meta/CycleCheck.h"
#include "ecoscore/meta/Tuple.h"
#include "ecoscore/meta/TypeList.h"
#include "ecoscore/meta/Variant.h"

#include "std.h"

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
#endif // __SRC_ECOSCORE_META_META_IXX__
