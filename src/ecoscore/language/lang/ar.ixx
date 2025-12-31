// /src/ecoscore/language/lang/ar.ixx
export module ecoscore.language.lang.ar;

import std;

import ecoscore.language.Languages;

namespace ecoscore::language::lang {

    struct Ar final : language::Language<Ar> {
    protected:
        constexpr Ar() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Arabic";
        }

        inline constexpr static auto& Ar = instance;
    };

}
