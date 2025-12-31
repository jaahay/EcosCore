// /src/ecoscore/tag/Outcomes.ixx
export module ecoscore.tag.Outcomes;

import ecoscore.tag.Category;

namespace ecoscore::tag::outcome {

    /**
     * @brief CRTP base for outcome tags.
     *
     * @tparam Derived The derived outcome tag.
     */
    export template <typename Derived>
        struct Outcome : Category<Derived> {
        protected:
            constexpr Outcome() noexcept = default;
            constexpr ~Outcome() noexcept = default;
    };

} // namespace ecoscore::tag::outcome
