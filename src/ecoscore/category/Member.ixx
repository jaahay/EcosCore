//// File: EcosCore/include/ecoscore/category/Member.ixx
export module ecoscore.category.Member;

import ecoscore.category.Category;

import std;

namespace ecoscore::category {

    /**
     * @brief CRTP base template implementing singleton and static polymorphism.
     * 
     * @note The static_name() method returns a canonical, internal identifier string.
     *       This string is a stable, machine-readable key used for compile-time dispatch,
     *       serialization, and metadata lookup.
     *
     *       It is NOT intended for display to end users and should never be localized.
     *       User-facing names and descriptions must be provided separately via localization data.
     * 
     * @tparam Derived The concrete derived category type.
     * @tparam Base The polymorphic base class, defaults to Category.
     */
    export template <typename Derived, typename Base = Category>
        struct Member : Base {
        protected:
            constexpr Member() noexcept = default;
            ~Member() noexcept override = default;

        public:
            Member(const Member&) = delete;
            Member& operator=(const Member&) = delete;

            /**
             * @brief Returns the singleton instance of the derived category.
             */
            [[nodiscard]] static const Derived& instance() noexcept {
                static Derived inst{};
                return inst;
            }

            /**
             * @brief Compile-time static method for static_name().
             *
             * Use this for constexpr contexts.
             */
            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }
    };

} // namespace ecoscore::category
