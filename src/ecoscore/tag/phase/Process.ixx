// include/ecoscore/tag/phase/Process.ixx
export module ecoscore.tag.phase.Process;

import ecoscore.tag.Phases;
import ecoscore.tag.concepts.Concepts;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'Process' phase.
     */
    struct Process final : tag::Phase<Process> {
        friend tag::Category<Process>;

    protected:
        constexpr Process() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Process";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Process",
                    "process",
                    "process",
                    "Process phase",
                    "P*******",
                    "Process",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Process", Charset::UTF8::instance() } },
                        { "execute", "run", "handle" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Process, tag::Phase>, "Process must satisfy Category concept");

}  // namespace ecoscore::tag::phase
