// include/ecoscore/tag/phase/Before.ixx
export module ecoscore.tag.phase.Before;

import ecoscore.tag.Phases;
import ecoscore.tag.concepts.Concepts;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'Before' phase.
     */
    struct Before final : tag::Phase<Before> {
        friend tag::Category<Before>;

    protected:
        constexpr Before() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Before";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Before",
                    "before",
                    "before",
                    "Before phase",
                    "B*****",
                    "Before",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Before", Charset::UTF8::instance() } },
                        { "prior", "earlier", "preceding" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Before, tag::Phase>, "Before must satisfy Category concept");

}  // namespace ecoscore::tag::phase
