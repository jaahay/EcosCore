// /src/ecoscore/language/lang/ko.ixx
export module ecoscore.language.lang.ko;

import std;

import ecoscore.language.Languages;
import ecoscore.tag.concepts.Category;

namespace ecoscore::language::lang {

    struct Ko final : language::Language<Ko> {
    protected:
        constexpr Ko() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Korean";
        }

        inline constexpr static auto& Ko = instance;
    };

}
