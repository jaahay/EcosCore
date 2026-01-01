//// File: EcosCore/src/ecoscore/category/phase/Finalize.ixx
export module ecoscore.category.phase.Finalize;

import ecoscore.category.Member;
import ecoscore.category.Phase;

namespace ecoscore::category::phase {

    export struct Finalize final : Member<Finalize, ecoscore::category::Phase> {
        friend Member<Finalize, ecoscore::category::Phase>;

    private:
        constexpr Finalize() noexcept = default;
        ~Finalize() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Finalize"; }
    };

} // namespace ecoscore::category::phase
