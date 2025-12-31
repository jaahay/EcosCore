// /src/ecoscore/language/lang/zh_hans.ixx
export module ecoscore.language.lang.zh_hans;

import std;

import ecoscore.language.Languages;
import ecoscore.tag.concepts.Category;

namespace ecoscore::language::lang {

    struct ZhHans final : language::Language<ZhHans> {
    protected:
        constexpr ZhHans() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "ChineseSimplified";
        }

        inline constexpr static auto& ZhHans = instance;
    };

}
