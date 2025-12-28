// src/ecoscore/type/TemplateType.ixx
module ecoscore.type.TemplateType;

import ecoscore.type.StructType;
import <typeinfo>;
import <string_view>;

export namespace ecoscore::type {

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

        static constexpr std::string_view name() noexcept {
            return typeid(Derived).name();
        }
    };

}
