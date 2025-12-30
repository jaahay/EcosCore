// include/ecoscore/tag/phase/Start.ixx
export module ecoscore.tag.phase.Start;

import ecoscore.tag.Phases;
import ecoscore.tag.concepts.Concepts;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'Start' phase.
     */
    struct Start final : tag::Phase<Start> {
        friend tag::Category<Start>;

    protected:
        constexpr Start() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Start";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Start",
                    "start",
                    "start",
                    "Start phase",
                    "S****",
                    "Start",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Start", Charset::UTF8::instance() } },
                        { "begin", "initiate", "commence" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Start, tag::Phase>, "Start must satisfy Category concept");

}  // namespace ecoscore::tag::phase
