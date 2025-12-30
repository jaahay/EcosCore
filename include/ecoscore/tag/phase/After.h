// include/ecoscore/tag/phase/After.h
#ifndef ECOSCORE_TAG_PHASE_AFTER_H
#define ECOSCORE_TAG_PHASE_AFTER_H

#include "ecoscore/tag/Phases.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include <string_view>

namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'After' phase.
     */
    struct After final : tag::Phase<After> {
        friend tag::Category<After>;

    protected:
        constexpr After() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "After";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "After",
                    "after",
                    "after",
                    "After phase",
                    "A****",
                    "After",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "After", Charset::UTF8::instance() } },
                        { "post", "later", "subsequent" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<After, tag::Phase>, "After must satisfy Category concept");

}  // namespace ecoscore::tag::phase

#endif  // ECOSCORE_TAG_PHASE_AFTER_H
