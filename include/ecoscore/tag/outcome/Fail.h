// include/ecoscore/tag/outcome/Fail.h
#ifndef ECOSCORE_TAG_OUTCOME_FAIL_H
#define ECOSCORE_TAG_OUTCOME_FAIL_H

#include "ecoscore/tag/Outcomes.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include <string_view>

namespace ecoscore::tag::outcome {

    /**
     * @brief Outcome tag indicating failure.
     */
    struct Fail final : tag::Outcome<Fail> {
        friend tag::Category<Fail>;

    protected:
        constexpr Fail() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Fail";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Fail",
                    "fail",
                    "fail",
                    "Failure outcome",
                    "F***",
                    "Fail",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Fail", Charset::UTF8::instance() } },
                        { "error", "fault", "break" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Fail, tag::Outcome>, "Fail must satisfy Category concept");

}  // namespace ecoscore::tag::outcome

#endif  // ECOSCORE_TAG_OUTCOME_FAIL_H
