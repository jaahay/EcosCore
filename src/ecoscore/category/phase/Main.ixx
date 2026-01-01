//// File: EcosCore/src/ecoscore/category/phase/Main.ixx
export module ecoscore.category.phase.Main;

import ecoscore.category.Member;
import ecoscore.category.Phase;

namespace ecoscore::category::phase {

    export struct Main final : Member<Main, ecoscore::category::Phase> {
        friend Member<Main, ecoscore::category::Phase>;

    private:
        constexpr Main() noexcept = default;
        ~Main() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Main"; }
    };

} // namespace ecoscore::category::phase
