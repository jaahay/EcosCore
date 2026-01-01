// File: ecoscore/meta/Meta.h
// /src/ecoscore/meta/Meta.ixx
#ifndef ECOSCORE_ECOSCORE_META_META_H
#define ECOSCORE_ECOSCORE_META_META_H

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
} // namespace ecoscore::meta
    };

}
#endif // ECOSCORE_ECOSCORE_META_META_H
