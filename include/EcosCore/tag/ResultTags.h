// EcosCore/tag/ResultTags.h
#ifndef ECOSCORE_TAG_RESULT_TAGS_H
#define ECOSCORE_TAG_RESULT_TAGS_H

#include "Tag.h"
#include "../type/TemplateType.h"
#include "NameSet.h"

namespace EcosCore::tag {

    /** Abstract categories for result dimensions */

    struct ResultFlow : Tag<ResultFlow> {
    protected:
        constexpr ResultFlow() noexcept = default;
    };

    struct ResultOutcome : Tag<ResultOutcome> {
    protected:
        constexpr ResultOutcome() noexcept = default;
    };

    /** Flow control tags (mutually exclusive) */

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
                {{"en", {{"Continue", "UTF-8"}}}}
            };
        }
    };

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
                {{"en", {{"Stop", "UTF-8"}}}}
            };
        }
    };

    struct Halt : type::TemplateType<Halt, ResultFlow> {
        static constexpr std::string_view name() noexcept { return "Halt"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Halt",
                "halt",
                "halt",
                "Halt processing",
                "H***",
                "Halt",
                {{"en", {{"Halt", "UTF-8"}}}}
            };
        }
    };

    /** Outcome tags (can combine) */

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
                {{"en", {{"Pass", "UTF-8"}}}}
            };
        }
    };

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
                {{"en", {{"Fail", "UTF-8"}}}}
            };
        }
    };

    struct Succeed : type::TemplateType<Succeed, ResultOutcome> {
        static constexpr std::string_view name() noexcept { return "Succeed"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Succeed",
                "succeed",
                "succeed",
                "Succeeded processing",
                "S******",
                "Suc...",
                {{"en", {{"Succeed", "UTF-8"}}}}
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
                {{"en", {{"Partial", "UTF-8"}}}}
            };
        }
    };

} // namespace EcosCore::tag

#endif // ECOSCORE_TAG_RESULT_TAGS_H
