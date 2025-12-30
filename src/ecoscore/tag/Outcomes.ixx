// include/ecoscore/tag/Outcomes.ixx
export module ecoscore.tag.Outcomes;

import ecoscore.tag.Category;

export namespace ecoscore::tag {

    /**
     * @brief CRTP base for outcome tags.
     *
     * @tparam Derived The derived outcome tag.
     */
    template <typename Derived>
    struct Outcome : Category<Derived> {
    protected:
        constexpr Outcome() noexcept = default;
    };

}  // namespace ecoscore::tag
