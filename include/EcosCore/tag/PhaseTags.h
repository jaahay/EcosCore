// include/ecoscore/tag/PhaseTags.h
#ifndef ECOSCORE_TAG_PHASE_TAGS_H
#define ECOSCORE_TAG_PHASE_TAGS_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/tag/NameSet.h"

namespace ecoscore::tag {

    /**
     * @brief Abstract phase category.
     */
    struct Phase : Tag<Phase> {
    protected:
        constexpr Phase() noexcept = default;
    };

    /**
     * @brief Concrete phases.
     */
    struct Before : type::TemplateType<Before, Phase> {
        static constexpr std::string_view name() noexcept { return "Before"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Before",
                "before",
                "before_phase",
                "Phase before main processing",
                "B*****",
                "Bef...",
                {{"en", {{"Before", "UTF-8"}}}},
                {"pre", "preprocess"} // synonyms example
            };
        }
    };

    struct Main : type::TemplateType<Main, Phase> {
        static constexpr std::string_view name() noexcept { return "Main"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Main",
                "main",
                "main_phase",
                "Main processing phase",
                "M***",
                "Main",
                {{"en", {{"Main", "UTF-8"}}}}
            };
        }
    };

    struct After : type::TemplateType<After, Phase> {
        static constexpr std::string_view name() noexcept { return "After"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "After",
                "after",
                "after_phase",
                "Phase after main processing",
                "A****",
                "Aft...",
                {{"en", {{"After", "UTF-8"}}}}
            };
        }
    };

    struct Error : type::TemplateType<Error, Phase> {
        static constexpr std::string_view name() noexcept { return "Error"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Error",
                "error",
                "error_phase",
                "Error handling phase",
                "E****",
                "Err...",
                {{"en", {{"Error", "UTF-8"}}}}
            };
        }
    };

    struct Finalize : type::TemplateType<Finalize, Phase> {
        static constexpr std::string_view name() noexcept { return "Finalize"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Finalize",
                "finalize",
                "finalize_phase",
                "Final cleanup phase",
                "F*******",
                "Fin...",
                {{"en", {{"Finalize", "UTF-8"}}}}
            };
        }
    };

} // namespace ecoscore::tag

#endif // ECOSCORE_TAG_PHASE_TAGS_H
