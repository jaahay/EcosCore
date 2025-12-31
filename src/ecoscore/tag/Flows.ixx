// /src/ecoscore/tag/Flows.ixx
export module ecoscore.tag.Flows;

import ecoscore.tag.Category;

namespace ecoscore::tag {

    /**
     * @brief CRTP base for flow control tags.
     *
     * @tparam Derived The derived flow tag.
     */
    export template <typename Derived>
        struct Flow : Category<Derived> {
        protected:
            constexpr Flow() noexcept = default;
            constexpr ~Flow() noexcept = default;
    };

} // namespace ecoscore::tag
