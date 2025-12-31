// /src/ecoscore/language/lang/de.ixx
export module ecoscore.language.lang.de;

import ecoscore.language.Languages;
import ecoscore.tag.concepts.Category;
import <string_view>;

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
