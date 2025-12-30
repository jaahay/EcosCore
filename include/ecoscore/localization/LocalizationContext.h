// include/ecoscore/localization/LocalizationContext.h
#ifndef ECOSCORE_LOCALIZATION_LOCALIZATIONCONTEXT_H
#define ECOSCORE_LOCALIZATION_LOCALIZATIONCONTEXT_H

#include "ecoscore/language/Locale.h"
#include "ecoscore/language/textrepresentation.h"
#include "ecoscore/concepts/Category.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/localization/Localizations.h"
#include <string_view>
#include <string>
#include <optional>

namespace ecoscore::localization {

    /**
     * @brief Runtime localization context representing exactly one locale and encoding.
     *
     * Provides localization queries with fallback to machine names.
     */
    class LocalizationContext {
    public:
        /**
         * @brief Constructs context with locale and optional encoding (default UTF-8).
         */
        explicit LocalizationContext(language::Locale locale,
            const language::textrepresentation::TextRepresentation& encoding = language::textrepresentation::UTF8::instance())
            : locale_(std::move(locale)), encoding_(encoding) {
        }

        /**
         * @brief Get localized canonical name for a tag.
         *
         * Returns fallback string if none found.
         */
        template <concepts::Category Tag>
        std::string get_canonical_name() const noexcept {
            return get_name<Tag>();
        }

        [[nodiscard]] const language::Locale& locale() const noexcept { return locale_; }
        [[nodiscard]] const language::textrepresentation::TextRepresentation& encoding() const noexcept { return encoding_; }

        void set_locale(language::Locale locale) noexcept { locale_ = std::move(locale); }
        void set_encoding(const language::textrepresentation::TextRepresentation& encoding) noexcept { encoding_ = encoding; }

    private:
        language::Locale locale_;
        const language::textrepresentation::TextRepresentation& encoding_;

        template <concepts::Category Tag>
        std::string get_name() const noexcept {
            using namespace language::lang;

            if (&locale_.language == &En) {
                return std::string{ Localization<Tag, En>::names.canonical_name };
            }
            if (&locale_.language == &Fr) {
                return std::string{ Localization<Tag, Fr>::names.canonical_name };
            }
            if (&locale_.language == &De) {
                return std::string{ Localization<Tag, De>::names.canonical_name };
            }
            if (&locale_.language == &Es) {
                return std::string{ Localization<Tag, Es>::names.canonical_name };
            }
            if (&locale_.language == &Ar) {
                return std::string{ Localization<Tag, Ar>::names.canonical_name };
            }
            if (&locale_.language == &ZhHans) {
                return std::string{ Localization<Tag, ZhHans>::names.canonical_name };
            }
            if (&locale_.language == &ZhHant) {
                return std::string{ Localization<Tag, ZhHant>::names.canonical_name };
            }
            if (&locale_.language == &Ja) {
                return std::string{ Localization<Tag, Ja>::names.canonical_name };
            }
            if (&locale_.language == &Ko) {
                return std::string{ Localization<Tag, Ko>::names.canonical_name };
            }

            // Fallback: machine-readable tag name + notice
            return std::string{ Tag::static_name() } + " (translation unavailable)";
        }
    };

}  // namespace ecoscore::localization

#endif  // ECOSCORE_LOCALIZATION_LOCALIZATIONCONTEXT_H
