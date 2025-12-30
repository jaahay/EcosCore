// include/ecoscore/tag/Category.ixx
export module ecoscore.tag.Category;

export namespace ecoscore::tag {

    /**
     * @brief CRTP base for all tag categories.
     *
     * Provides compile-time singleton instance and static_name().
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
