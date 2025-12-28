// include/ecoscore/tag/SynonymTag.h
#ifndef ECOSCORE_TAG_SYNONYM_TAG_H
#define ECOSCORE_TAG_SYNONYM_TAG_H

namespace ecoscore::tag {

    /**
     * @brief Trait to map a tag type to its canonical tag type.
     *
     * By default, a tag is canonical to itself.
     * Specialize in domain headers to redirect synonyms to canonical tags.
     */
    template <typename TagT>
    struct SynonymTag {
        using type = TagT;
    };

    /**
     * @brief Helper alias to get canonical tag type.
     */
    template <typename TagT>
    using canonical_tag_t = typename SynonymTag<TagT>::type;

} // namespace ecoscore::tag

#endif // ECOSCORE_TAG_SYNONYM_TAG_H
