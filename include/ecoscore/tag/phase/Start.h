// include/ecoscore/tag/phase/Start.h
#ifndef ECOSCORE_TAG_PHASE_START_H
#define ECOSCORE_TAG_PHASE_START_H

#include "ecoscore/tag/Phases.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include <string_view>

namespace ecoscore::tag::phase {

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

#endif  // ECOSCORE_TAG_PHASE_START_H
