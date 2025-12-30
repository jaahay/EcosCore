// include/ecoscore/tag/phase/Finalize.ixx
export module ecoscore.tag.phase.Finalize;

import ecoscore.tag.Phases;
import ecoscore.tag.concepts.Concepts;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'Finalize' phase.
     */
    struct Finalize final : tag::Phase<Finalize> {
        friend tag::Category<Finalize>;

    protected:
        constexpr Finalize() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Finalize";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Finalize",
                    "finalize",
                    "finalize",
                    "Finalize phase",
                    "F*******",
                    "Finalize",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Finalize", Charset::UTF8::instance() } },
                        { "complete", "finish", "wrap up" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Finalize, tag::Phase>, "Finalize must satisfy Category concept");

}  // namespace ecoscore::tag::phase
