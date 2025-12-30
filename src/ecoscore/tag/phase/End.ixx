// include/ecoscore/tag/phase/End.ixx
export module ecoscore.tag.phase.End;

import ecoscore.tag.Phases;
import ecoscore.tag.concepts.Concepts;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'End' phase.
     */
    struct End final : tag::Phase<End> {
        friend tag::Category<End>;

    protected:
        constexpr End() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "End";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "End",
                    "end",
                    "end",
                    "End phase",
                    "E**",
                    "End",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "End", Charset::UTF8::instance() } },
                        { "finish", "stop", "terminate" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<End, tag::Phase>, "End must satisfy Category concept");

}  // namespace ecoscore::tag::phase
