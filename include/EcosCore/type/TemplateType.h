// EcosCore/type/TemplateType.h
#ifndef ECOSCORE_TYPE_TEMPLATE_TYPE_H
#define ECOSCORE_TYPE_TEMPLATE_TYPE_H

#include "StructType.h"
#include <typeinfo>
#include <string_view>

namespace ecoscore::type {

    /**
     * CRTP base to provide compile-time type identity and printing.
     */
    template <typename Derived, typename Parent = StructType>
    struct TemplateType : Parent {
        void print(std::ostream& os) const override {
            os << typeid(Derived).name();
        }

        static constexpr std::string_view name() noexcept {
            return typeid(Derived).name();
        }
    };

} // namespace ecoscore::type

#endif // ECOSCORE_TYPE_TEMPLATE_TYPE_H
