// /src/ecoscore/language/lang/zh_hant.ixx
export module ecoscore.language.lang.zh_hant;

import ecoscore.language.Languages;
import ecoscore.tag.concepts.Category;
import <string_view>;

namespace ecoscore::language::lang {

    struct ZhHant final : language::Language<ZhHant> {
    protected:
        constexpr ZhHant() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "ChineseTraditional";
        }

        inline constexpr static auto& ZhHant = instance;
    };

}
