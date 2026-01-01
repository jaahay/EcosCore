//// File: EcosCore/src/ecoscore/category/phase/Error.ixx
export module ecoscore.category.phase.Error;

import ecoscore.category.Member;
import ecoscore.category.Phase;

namespace ecoscore::category::phase {

    export struct Error final : Member<Error, ecoscore::category::Phase> {
        friend Member<Error, ecoscore::category::Phase>;

    private:
        constexpr Error() noexcept = default;
        ~Error() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Error"; }
    };

} // namespace ecoscore::category::phase
