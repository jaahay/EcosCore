// File: ecoscore/category/Member.h
#ifndef ECOSCORE_CATEGORY_MEMBER_H_
#define ECOSCORE_CATEGORY_MEMBER_H_

/**
 * @file Member.h
 * @brief CRTP base template enforcing static constexpr name() for category members.
 *
 * @details
 * This template provides a base class for category members using CRTP.
 * It enforces a static constexpr interface without runtime polymorphism.
 * Copy and move operations are deleted to maintain immutability and singleton behavior.
 *
 * @tparam Derived The concrete derived category type.
 * @tparam Base The base class, defaults to ecoscore::category::Category.
 */

#include "ecoscore/category/Category.h"
#include <string_view>

namespace ecoscore::category {

    /**
     * @brief CRTP base template enforcing static constexpr name().
     *
     * No runtime polymorphism.
     *
     * @tparam Derived The concrete derived category type.
     * @tparam Base The base class, defaults to Category.
     */
    template <typename Derived, typename Base = ecoscore::category::Category>
    struct Member : Base {
    protected:
        /**
         * @brief Protected default constructor to prevent direct instantiation.
         */
        constexpr Member() noexcept = default;

        /**
         * @brief Protected destructor.
         */
        ~Member() noexcept = default;

    public:
        // Deleted copy constructor and copy assignment operator
        Member(const Member&) = delete;
        Member& operator=(const Member&) = delete;

        // Deleted move constructor and move assignment operator
        Member(Member&&) = delete;
        Member& operator=(Member&&) = delete;

        /**
         * @brief Returns the singleton instance of the derived category.
         * @return constexpr reference to the instance.
         */
        [[nodiscard]] static constexpr const Derived& instance() noexcept {
            return inst;
        }

        /**
         * @brief Compile-time category name.
         * @return constexpr std::string_view of the category name.
         */
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return Derived::name();
        }

    private:
        /// Static constexpr instance of Derived, inline for C++17.
        static inline constexpr Derived inst{};
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_MEMBER_H_
