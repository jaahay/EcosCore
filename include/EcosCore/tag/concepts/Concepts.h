// EcosCore/tag/concepts/Concepts.h
#ifndef ECOSCORE_TAG_CONCEPTS_CONCEPTS_H
#define ECOSCORE_TAG_CONCEPTS_CONCEPTS_H

#include <concepts>
#include "EcosCore/tag/Tag.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"
#include "EcosCore/tag/CharsetTags.h"
#include "EcosCore/tag/LanguageTags.h"
#include "EcosCore/tag/ResultTags.h"

namespace EcosCore::tag::concepts {

    /**
     * Concept for singleton tag types.
     */
    template <typename T>
    concept SingletonTag = requires {
        { T::instance() } -> std::same_as<const T&>;
        { T::name() } -> std::convertible_to<const char*>;
    };

    /**
     * Concept for tag categories.
     */
    template <typename T>
    concept TagCategory = std::derived_from<T, EcosCore::tag::Tag<T>>;

    /**
     * Concept for phase tags.
     */
    template <typename T>
    concept PhaseTag = std::derived_from<T, EcosCore::tag::Phase>;

    /**
     * Concept for priority tags.
     */
    template <typename T>
    concept PriorityTag = std::derived_from<T, EcosCore::tag::Priority>;

    /**
     * Concept for charset tags.
     */
    template <typename T>
    concept CharsetTag = std::derived_from<T, EcosCore::tag::Charset>;

    /**
     * Concept for language tags.
     */
    template <typename T>
    concept LanguageTag = std::derived_from<T, EcosCore::tag::Language>;

    /**
     * Concept for result tags.
     */
    template <typename T>
    concept ResultTag = std::derived_from<T, EcosCore::tag::Result>;

} // namespace EcosCore::tag::concepts

#endif // ECOSCORE_TAG_CONCEPTS_CONCEPTS_H
