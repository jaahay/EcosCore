// /src/ecoscore/language/lang/en.ixx
export module ecoscore.language.lang.en;

import std;

import ecoscore.language.Languages;

namespace ecoscore::language::lang {

    struct En final : language::Language<En> {
    protected:
        constexpr En() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "English";
        }

        inline constexpr static auto& En = instance;
    };

}
