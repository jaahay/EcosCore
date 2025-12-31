// /src/ecoscore/language/lang/de.ixx
export module ecoscore.language.lang.de;

import std;

import ecoscore.language.Languages;    

namespace ecoscore::language::lang {

    struct De final : language::Language<De> {
    protected:
        constexpr De() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "German";
        }

        inline constexpr static auto& De = instance;
    };

}
