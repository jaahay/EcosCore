// src/ecoscore/type/TemplateType.ixx
export module ecoscore.type.TemplateType;

import ecoscore.type.StructType;
import <typeinfo>;
import <string_view>;
import <type_traits>;

export namespace ecoscore::type {

    /**
     * @brief CRTP base to provide compile-time type identity and printing.
     * @tparam Derived Derived type.
     * @tparam Parent Parent type (defaults to StructType).
     */
    template <typename Derived, typename Parent = StructType>
    struct TemplateType : Parent {
        static_assert(std::is_base_of_v<Parent, Derived>, "Derived must inherit from Parent");

        void print(std::ostream& os) const noexcept override {
            os << typeid(Derived).name();
        }

        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return typeid(Derived).name();
        }
    };

} // namespace ecoscore::type
