// File: ecoscore/category/Member.h
#ifndef ECOSCORE_CATEGORY_MEMBER_H_
#define ECOSCORE_CATEGORY_MEMBER_H_

#include "ecoscore/category/Category.h"

namespace ecoscore::category {

    /**
     * @brief CRTP base class for singleton members of a category.
     *
     * @tparam Derived The concrete derived member type.
     * @tparam Base The category base type (defaults to Category).
     */
    template <typename Derived, typename Base = Category>
    struct Member : Base {
    protected:
        constexpr Member() noexcept
            : Base()
            , wrapper_(Wrapper::instance())
        {
        }

    public:
        Member(const Member&) = delete;
        Member& operator=(const Member&) = delete;
        ~Member() noexcept = default;

        std::string_view name() const noexcept {
            return wrapper_.name();
        }

        static constexpr const Derived& Instance = Derived::instance();

    private:
        struct Wrapper final : Category::Wrapper {
            static const Wrapper& instance() {
                static const Wrapper inst{};
                return inst;
            }

            std::string_view name() const noexcept {
                return Derived::name();
            }
        };

        const Wrapper& wrapper_;
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_MEMBER_H_
