// File: ecoscore/category/Member.h
#ifndef ECOSCORE_CATEGORY_MEMBER_H_
#define ECOSCORE_CATEGORY_MEMBER_H_

#include "ecoscore/category/Category.h"
#include <string_view>

namespace ecoscore::category {

    template <typename Derived, typename Base = Category>
    struct Member : Base {
    private:
        static constexpr Derived createInstance() {
            return Derived::create();
        }

    public:
        static inline constexpr Derived instance = createInstance();

        static constexpr std::string_view name() noexcept {
            return Derived::name();
        }

    protected:
        constexpr Member() noexcept = default;
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_MEMBER_H_
