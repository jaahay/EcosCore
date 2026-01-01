//// File: EcosCore/src/ecoscore/category/Category.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_CATEGORY_IXX__
#define __SRC_ECOSCORE_CATEGORY_CATEGORY_IXX__

#include "std.h"

namespace ecoscore::category {

    /**
     * @brief Marker base for all category tags.
     *
     * No virtual functions; all interface is static constexpr.
     */
struct Category {
        Category() noexcept = default;
        Category(const Category&) = delete;
        Category& operator=(const Category&) = delete;
        Category(Category&&) = delete;
        Category& operator=(Category&&) = delete;
    };

} // namespace ecoscore::category
#endif // __SRC_ECOSCORE_CATEGORY_CATEGORY_IXX__
