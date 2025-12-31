// /src/ecoscore/tag/Phases.ixx
export module ecoscore.tag.Phases;

import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    /**
     * @brief CRTP base for phase tags.
     *
     * @tparam Derived The derived phase tag.
     */
    export template <typename Derived>
        struct Phase : Category<Derived> {
        protected:
            constexpr Phase() noexcept = default;
            constexpr ~Phase() noexcept = default;
    };

} // namespace ecoscore::tag::phase
