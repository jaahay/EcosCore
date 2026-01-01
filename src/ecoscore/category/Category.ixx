//// File: EcosCore/src/ecoscore/category/Category.ixx
export module ecoscore.category.Category;

import std;

namespace ecoscore::category {

    /**
     * @brief Marker base for all category tags.
     *
     * No virtual functions; all interface is static constexpr.
     */
    export struct Category {
        Category() noexcept = default;
        Category(const Category&) = delete;
        Category& operator=(const Category&) = delete;
        Category(Category&&) = delete;
        Category& operator=(Category&&) = delete;
    };

} // namespace ecoscore::category
