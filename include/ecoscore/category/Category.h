// File: ecoscore/category/Category.h
//// File: EcosCore/src/ecoscore/category/Category.ixx
#ifndef ECOSCORE_CATEGORY_CATEGORY_H
#define ECOSCORE_CATEGORY_CATEGORY_H

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
#endif // ECOSCORE_CATEGORY_CATEGORY_H
