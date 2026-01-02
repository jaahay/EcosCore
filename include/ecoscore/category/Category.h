// File: ecoscore/include/category/Category.h
#ifndef ECOSCORE_CATEGORY_CATEGORY_H
#define ECOSCORE_CATEGORY_CATEGORY_H

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
