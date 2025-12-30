// include/ecoscore/tag/Phases.ixx
export module ecoscore.tag.Phases;

import ecoscore.tag.Category;

export namespace ecoscore::tag {

    /**
     * @brief CRTP base for phase tags.
     *
     * @tparam Derived The derived phase tag.
     */
    template <typename Derived>
    struct Phase : Category<Derived> {
    protected:
        constexpr Phase() noexcept = default;
    };

}  // namespace ecoscore::tag
