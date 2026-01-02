// File: ecoscore/include/category/Category.h
#ifndef ECOSCORE_CATEGORY_CATEGORY_H_
#define ECOSCORE_CATEGORY_CATEGORY_H_

/**
 * @file Category.h
 * @brief Marker base struct for all category tags.
 *
 * @details
 * This struct serves as a tag base for category types.
 * It contains no virtual functions and enforces a static constexpr interface.
 * Copy and move operations are explicitly deleted to prevent misuse.
 */

namespace ecoscore::category {

    /**
     * @brief Marker base for all category tags.
     *
     * @note No virtual functions; all interface is static constexpr.
     */
    struct Category {
        Category() noexcept = default;

        // Deleted copy constructor and copy assignment operator
        Category(const Category&) = delete;
        Category& operator=(const Category&) = delete;

        // Deleted move constructor and move assignment operator
        Category(Category&&) = delete;
        Category& operator=(Category&&) = delete;
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_CATEGORY_H_
