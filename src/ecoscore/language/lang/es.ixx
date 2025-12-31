// /src/ecoscore/language/lang/es.ixx
export module ecoscore.language.lang.es;

import std;

import ecoscore.language.Languages;
import ecoscore.tag.concepts.Category;

namespace ecoscore::language::lang {

    struct Es final : language::Language<Es> {
    protected:
        constexpr Es() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Spanish";
        }

        inline constexpr static auto& Es = instance;
    };

}
