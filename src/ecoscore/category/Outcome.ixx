//// File: EcosCore/src/ecoscore/category/Outcome.ixx
export module ecoscore.category.Outcome;

import ecoscore.category.Category;

namespace ecoscore::category {

    /**
     * @brief Marker base for outcome categories.
     */
    export struct Outcome : Category {
        Outcome() noexcept = default;
        Outcome(const Outcome&) = delete;
        Outcome& operator=(const Outcome&) = delete;
        Outcome(Outcome&&) = delete;
        Outcome& operator=(Outcome&&) = delete;
        ~Outcome() noexcept = default;
    };

} // namespace ecoscore::category
