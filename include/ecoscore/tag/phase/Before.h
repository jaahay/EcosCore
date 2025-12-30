// include/ecoscore/tag/phase/Before.h
#ifndef ECOSCORE_TAG_PHASE_BEFORE_H
#define ECOSCORE_TAG_PHASE_BEFORE_H

#include "ecoscore/tag/Phases.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include <string_view>

namespace ecoscore::tag::phase {

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

#endif  // ECOSCORE_TAG_PHASE_BEFORE_H
