//// File: EcosCore/include/ecoscore/category/Virtual.ixx
export module ecoscore.category.Virtual;

import std;

namespace ecoscore::category {

    /**
     * @brief Pure virtual base interface for categories.
     *
     * Contains only virtual interface methods and a virtual destructor.
     * This is the minimal polymorphic base class.
     */
    export struct Virtual {
        virtual ~Virtual() noexcept = default;

        /**
         * @brief Returns a canonical, stable identifier string.
         *
         * This string must be machine-readable and not localized.
         */
        [[nodiscard]] virtual std::string_view static_name() const noexcept = 0;
    };

} // namespace ecoscore::category
