// include/ecoscore/tag/phase/Error.ixx
export module ecoscore.tag.phase.Error;

import ecoscore.tag.Phases;
import ecoscore.tag.concepts.Concepts;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'Error' phase.
     */
    struct Error final : tag::Phase<Error> {
        friend tag::Category<Error>;

    protected:
        constexpr Error() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Error";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Error",
                    "error",
                    "error",
                    "Error phase",
                    "E****",
                    "Error",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Error", Charset::UTF8::instance() } },
                        { "fault", "fail", "bug" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Error, tag::Phase>, "Error must satisfy Category concept");

}  // namespace ecoscore::tag::phase
