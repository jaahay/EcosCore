//// File: EcosCore/src/ecoscore/category/Member.ixx
export module ecoscore.category.Member;

import ecoscore.category.Category;

import std;

namespace ecoscore::category {

    /**
     * @brief CRTP base template enforcing static constexpr name().
     *
     * No runtime polymorphism.
     *
     * @tparam Derived The concrete derived category type.
     * @tparam Base The base class, defaults to Category.
     */
    export template <typename Derived, typename Base = ecoscore::category::Category>
    struct Member : Base {
        //static_assert(std::is_base_of_v<Base, Derived>, "Derived must inherit from Base");
        //static_assert(requires { Derived::name(); }, "Derived must implement static constexpr name()");

    protected:
        constexpr Member() noexcept = default;
        ~Member() noexcept = default;

    public:
        Member(const Member&) = delete;
        Member& operator=(const Member&) = delete;
        Member(Member&&) = delete;
        Member& operator=(Member&&) = delete;

        /**
         * @brief Returns the singleton instance of the derived category.
         */
        [[nodiscard]] static const Derived& instance() noexcept {
            static Derived inst{};
            return inst;
        }

        /**
         * @brief Compile-time category name.
         */
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return Derived::name();
        }
    };

} // namespace ecoscore::category
