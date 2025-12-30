// include/ecoscore/tag/outcome/Pass.h
#ifndef ECOSCORE_TAG_OUTCOME_PASS_H
#define ECOSCORE_TAG_OUTCOME_PASS_H

#include "ecoscore/tag/Outcomes.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include <string_view>

namespace ecoscore::tag::outcome {

    /**
     * @brief Outcome tag indicating success.
     */
    struct Pass final : tag::Outcome<Pass> {
        friend tag::Category<Pass>;

    protected:
        constexpr Pass() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Pass";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Pass",
                    "pass",
                    "pass",
                    "Success outcome",
                    "P***",
                    "Pass",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Pass", Charset::UTF8::instance() } },
                        { "success", "ok", "win" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Pass, tag::Outcome>, "Pass must satisfy Category concept");

}  // namespace ecoscore::tag::outcome

#endif  // ECOSCORE_TAG_OUTCOME_PASS_H
