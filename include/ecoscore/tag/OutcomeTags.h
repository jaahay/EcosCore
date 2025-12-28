// include/ecoscore/tag/OutcomeTags.h
#ifndef ECOSCORE_TAG_OUTCOME_TAGS_H
#define ECOSCORE_TAG_OUTCOME_TAGS_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/tag/NameSet.h"

namespace ecoscore::tag {

    /**
     * @brief Outcome tags (can combine).
     */
    struct Pass : type::TemplateType<Pass, ResultOutcome> {
        static constexpr std::string_view name() noexcept { return "Pass"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Pass",
                "pass",
                "pass",
                "Passed successfully",
                "P***",
                "Pass",
                {{"en", {{"Pass", "UTF-8"}}}},
                {"success", "ok", "approved"}
            };
        }
    };

    using Success = Pass;
    using Succeed = Pass;

    struct Fail : type::TemplateType<Fail, ResultOutcome> {
        static constexpr std::string_view name() noexcept { return "Fail"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Fail",
                "fail",
                "fail",
                "Failed processing",
                "F***",
                "Fail",
                {{"en", {{"Fail", "UTF-8"}}}},
                {"error", "rejected", "unsuccessful"}
            };
        }
    };

    struct Partial : type::TemplateType<Partial, ResultOutcome> {
        static constexpr std::string_view name() noexcept { return "Partial"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Partial",
                "partial",
                "partial",
                "Partially succeeded",
                "P******",
                "Par...",
                {{"en", {{"Partial", "UTF-8"}}}},
                {"incomplete", "partial success"}
            };
        }
    };

} // namespace ecoscore::tag

#endif // ECOSCORE_TAG_OUTCOME_TAGS_H
