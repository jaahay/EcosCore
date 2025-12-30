// include/ecoscore/tag/Category.h
#ifndef ECOSCORE_TAG_CATEGORY_H
#define ECOSCORE_TAG_CATEGORY_H

#include <string_view>
#include <type_traits>

namespace ecoscore::tag {

    /**
     * @brief CRTP base for all tag categories.
     *
     * Provides compile-time singleton instance and static_name().
     * 
     * @note The static_name() method returns a canonical, internal identifier string.
     *       This string is a stable, machine-readable key used for compile-time dispatch,
     *       serialization, and metadata lookup.
     *
     *       It is NOT intended for display to end users and should never be localized.
     *       User-facing names and descriptions must be provided separately via localization data.
     * 
     * @tparam Derived The derived tag type.
     */
    template <typename Derived>
    struct Category {
    protected:
        constexpr Category() noexcept = default;

    public:
        Category(const Category&) = delete;
        Category& operator=(const Category&) = delete;

        [[nodiscard]] static constexpr const Derived& instance() noexcept {
            static constexpr Derived inst{};
            return inst;
        }

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return Derived::static_name();
        }

        static_assert(std::is_final_v<Derived>, "Category derived types should be final for immutability.");
    };

}  // namespace ecoscore::tag

#endif  // ECOSCORE_TAG_CATEGORY_H
