// include/ecoscore/tag/phase/Main.ixx
export module ecoscore.tag.phase.Main;

import ecoscore.tag.Phases;
import ecoscore.tag.concepts.Concepts;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'Main' phase.
     */
    struct Main final : tag::Phase<Main> {
        friend tag::Category<Main>;

    protected:
        constexpr Main() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Main";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Main",
                    "main",
                    "main",
                    "Main phase",
                    "M***",
                    "Main",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Main", Charset::UTF8::instance() } },
                        { "primary", "core", "central" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Main, tag::Phase>, "Main must satisfy Category concept");

}  // namespace ecoscore::tag::phase
