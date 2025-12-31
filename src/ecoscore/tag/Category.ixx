// /src/ecoscore/tag/Category.ixx
export module ecoscore.tag.Category;

#include <string_view>
#include <type_traits>

namespace ecoscore::tag {

    /**
     * @brief CRTP base for all tag categories.
     *
     * Provides a compile-time singleton instance and static_name().
     *
     * Supports both abstract intermediate tags (non-final) and concrete leaf tags (final).
     *
     * @note The static_name() method returns a canonical, internal identifier string.
     *       This string is a stable, machine-readable key used for compile-time dispatch,
     *       serialization, and metadata lookup.
     *
     *       It is NOT intended for display to end users and should never be localized.
     *       User-facing names and descriptions must be provided separately via localization data.
     *
     * @tparam Derived The derived tag type.
     * @tparam IsLeaf Indicates if this is a leaf (concrete) tag type. Defaults to true.
     */
    export template <typename Derived, bool IsLeaf = true>
        struct Category {
        protected:
            constexpr Category() noexcept = default;
            constexpr ~Category() noexcept = default;

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

            static_assert(!IsLeaf || std::is_final_v<Derived>,
                "Category derived types marked as leaf must be final for immutability.");
    };

} // namespace ecoscore::tag
