// include/ecoscore/tag/phase/End.h
#ifndef ECOSCORE_TAG_PHASE_END_H
#define ECOSCORE_TAG_PHASE_END_H

#include "ecoscore/tag/Phases.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include <string_view>

namespace ecoscore::tag::phase {

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

#endif  // ECOSCORE_TAG_PHASE_END_H
