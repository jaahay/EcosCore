// /src/ecoscore/language/lang/ar.ixx
export module ecoscore.language.lang.ar;

import ecoscore.language.Languages;
import ecoscore.tag.concepts.Category;
import <string_view>;

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
