// File: ecoscore/category/Category.h
#ifndef ECOSCORE_CATEGORY_CATEGORY_H_
#define ECOSCORE_CATEGORY_CATEGORY_H_

#include <string_view>

namespace ecoscore::category {

    struct Category {
    protected:
        constexpr Category() noexcept = default;

    public:
        Category(const Category&) = delete;
        Category& operator=(const Category&) = delete;
        ~Category() noexcept = default;

        static constexpr std::string_view name() noexcept {
            return "Category";
        }
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_CATEGORY_H_
