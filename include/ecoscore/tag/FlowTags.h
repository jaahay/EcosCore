// include/ecoscore/tag/FlowTags.h
#ifndef ECOSCORE_TAG_FLOW_TAGS_H
#define ECOSCORE_TAG_FLOW_TAGS_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/tag/NameSet.h"

namespace ecoscore::tag {

    /**
     * @brief Flow control tags (mutually exclusive).
     */
    struct Continue : type::TemplateType<Continue, ResultFlow> {
        static constexpr std::string_view name() noexcept { return "Continue"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Continue",
                "continue",
                "continue",
                "Continue processing",
                "C*******",
                "Cont...",
                {{"en", {{"Continue", "UTF-8"}}}},
                {"cont", "proceed", "go on"}
            };
        }
    };

    using Proceed = Continue;

    struct Stop : type::TemplateType<Stop, ResultFlow> {
        static constexpr std::string_view name() noexcept { return "Stop"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Stop",
                "stop",
                "stop",
                "Stop processing",
                "S**",
                "Stop",
                {{"en", {{"Stop", "UTF-8"}}}},
                {"halt", "pause", "end"}
            };
        }
    };

    using End = Stop;
    using Halt = Stop;

} // namespace ecoscore::tag

#endif // ECOSCORE_TAG_FLOW_TAGS_H
