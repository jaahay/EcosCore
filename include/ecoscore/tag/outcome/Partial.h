// include/ecoscore/tag/outcome/Partial.h
#ifndef ECOSCORE_TAG_OUTCOME_PARTIAL_H
#define ECOSCORE_TAG_OUTCOME_PARTIAL_H

#include "ecoscore/tag/Outcomes.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include <string_view>

namespace ecoscore::tag::outcome {

    /**
     * @brief Outcome tag indicating partial success.
     */
    struct Partial final : tag::Outcome<Partial> {
        friend tag::Category<Partial>;

    protected:
        constexpr Partial() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Partial";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Partial",
                    "partial",
                    "partial",
                    "Partial success outcome",
                    "Pa***",
                    "Partial",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Partial", Charset::UTF8::instance() } },
                        { "some", "half", "part" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Partial, tag::Outcome>, "Partial must satisfy Category concept");

}  // namespace ecoscore::tag::outcome

#endif  // ECOSCORE_TAG_OUTCOME_PARTIAL_H
