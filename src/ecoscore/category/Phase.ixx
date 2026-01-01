//// File: EcosCore/src/ecoscore/category/Phase.ixx
export module ecoscore.category.Phase;

import ecoscore.category.Category;

namespace ecoscore::category {

    /**
     * @brief Marker base for phase categories.
     */
    export struct Phase : Category {
        Phase() noexcept = default;
        Phase(const Phase&) = delete;
        Phase& operator=(const Phase&) = delete;
        Phase(Phase&&) = delete;
        Phase& operator=(Phase&&) = delete;
        ~Phase() noexcept = default;
    };

} // namespace ecoscore::category
