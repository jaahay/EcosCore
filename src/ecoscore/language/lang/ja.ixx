// /src/ecoscore/language/lang/ja.ixx
export module ecoscore.language.lang.ja;

import std;

import ecoscore.language.Languages;

namespace ecoscore::language::lang {

    struct Ja final : language::Language<Ja> {
    protected:
        constexpr Ja() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Japanese";
        }

        inline constexpr static auto& Ja = instance;
    };

}
