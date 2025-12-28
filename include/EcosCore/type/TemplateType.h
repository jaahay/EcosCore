// include/ecoscore/type/TemplateType.h
#ifndef ECOSCORE_TYPE_TEMPLATE_TYPE_H
#define ECOSCORE_TYPE_TEMPLATE_TYPE_H

#include "StructType.h"
#include <typeinfo>
#include <string_view>

namespace ecoscore::type {

    /**
     * @brief CRTP base to provide compile-time type identity and printing.
     * @tparam Derived Derived type.
     * @tparam Parent Parent type (defaults to StructType).
     */
    template <typename Derived, typename Parent = StructType>
    struct TemplateType : Parent {
        void print(std::ostream& os) const noexcept override {
            os << typeid(Derived).name();
        }

        /**
         * @brief Returns the name of the derived type.
         * @return constexpr string_view of type name.
         */
        static constexpr std::string_view name() noexcept {
            return typeid(Derived).name();
        }
    };

} // namespace ecoscore::type

#endif // ECOSCORE_TYPE_TEMPLATE_TYPE_H
