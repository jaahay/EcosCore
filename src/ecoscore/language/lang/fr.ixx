// /src/ecoscore/language/lang/fr.ixx
export module ecoscore.language.lang.fr;

import ecoscore.language.Languages;
import ecoscore.tag.concepts.Category;
import <string_view>;

namespace ecoscore::language::lang {

    struct Fr final : language::Language<Fr> {
    protected:
        constexpr Fr() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "French";
        }

        inline constexpr static auto& Fr = instance;
    };

}
