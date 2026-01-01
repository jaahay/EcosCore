//// File: EcosCore/src/ecoscore/category/Flow.ixx
export module ecoscore.category.Flow;

import ecoscore.category.Category;

namespace ecoscore::category {

    /**
     * @brief Marker base for flow categories.
     */
    export struct Flow : Category {
        Flow() noexcept = default;
        Flow(const Flow&) = delete;
        Flow& operator=(const Flow&) = delete;
        Flow(Flow&&) = delete;
        Flow& operator=(Flow&&) = delete;
        ~Flow() noexcept = default;
    };

} // namespace ecoscore::category
