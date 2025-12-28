// EcosCore/tag/PriorityTags.h
#ifndef ECOSCORE_TAG_PRIORITY_TAGS_H
#define ECOSCORE_TAG_PRIORITY_TAGS_H

#include "Tag.h"
#include "EcosCore/type/TemplateType.h"
#include "NameSet.h"

namespace EcosCore::tag {

    /** Abstract priority category */
    struct Priority : Tag<Priority> {
    protected:
        constexpr Priority() noexcept = default;
    };

    /** Concrete priority tags */

    struct High : type::TemplateType<High, Priority> {
        static constexpr std::string_view name() noexcept { return "High"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "High",
                "high",
                "high_priority",
                "High priority",
                "H***",
                "High...",
                {{"en", {{"High", "UTF-8"}}}}
            };
        }
    };

    struct Medium : type::TemplateType<Medium, Priority> {
        static constexpr std::string_view name() noexcept { return "Medium"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Medium",
                "medium",
                "medium_priority",
                "Medium priority",
                "M*****",
                "Med...",
                {{"en", {{"Medium", "UTF-8"}}}}
            };
        }
    };

    struct Low : type::TemplateType<Low, Priority> {
        static constexpr std::string_view name() noexcept { return "Low"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Low",
                "low",
                "low_priority",
                "Low priority",
                "L**",
                "Low",
                {{"en", {{"Low", "UTF-8"}}}}
            };
        }
    };

} // namespace EcosCore::tag

#endif // ECOSCORE_TAG_PRIORITY_TAGS_H
