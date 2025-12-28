// include/ecoscore/language/NameSet.h
#ifndef ECOSCORE_LANGUAGE_NAME_SET_H
#define ECOSCORE_LANGUAGE_NAME_SET_H

#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <iostream>
#include "LocalizedName.h"

namespace ecoscore::language {

    /**
     * @brief Represents a set of names for a language-related tag, including localized and alternate forms.
     */
    struct NameSet {
        const std::string name;
        const std::string external_key;
        const std::string primary_key;
        const std::string alt_text_name;
        const std::string obfuscated_name;
        const std::string truncated_name;

        const std::map<std::string, std::vector<LocalizedName>> localized_names;
        const std::vector<std::string> synonyms;

        /**
         * @brief Constructs a NameSet with given parameters.
         *
         * @param n Main name.
         * @param ext_key External key.
         * @param primary Primary key (defaults to name if empty).
         * @param alt_text Alternate text name (defaults to name if empty).
         * @param obfuscated Obfuscated name (defaults to generated if empty).
         * @param truncated Truncated name (defaults to generated if empty).
         * @param localized Map of localized names by language.
         * @param syns Optional synonyms.
         */
        NameSet(
            std::string n,
            std::string ext_key,
            std::string primary,
            std::string alt_text,
            std::string obfuscated,
            std::string truncated,
            std::map<std::string, std::vector<LocalizedName>> localized,
            std::vector<std::string> syns = {})
            : name(std::move(n)),
            external_key(std::move(ext_key)),
            primary_key(primary.empty() ? name : std::move(primary)),
            alt_text_name(alt_text.empty() ? name : std::move(alt_text)),
            obfuscated_name(obfuscated.empty() ? GenerateObfuscated(name) : std::move(obfuscated)),
            truncated_name(truncated.empty() ? GenerateTruncated(name) : std::move(truncated)),
            localized_names(std::move(localized)),
            synonyms(std::move(syns)) {
        }

        static std::string GenerateObfuscated(const std::string& base) {
            return std::string(base.size(), '*');
        }

        static std::string GenerateTruncated(const std::string& base) {
            if (base.size() <= 8) return base;
            return base.substr(0, 8) + "...";
        }

        std::string_view GetAltTextName() const noexcept {
            return alt_text_name.empty() ? name : alt_text_name;
        }

        std::string_view GetObfuscatedName() const noexcept {
            return obfuscated_name.empty() ? GenerateObfuscated(name) : obfuscated_name;
        }

        std::string_view GetTruncatedName() const noexcept {
            return truncated_name.empty() ? GenerateTruncated(name) : truncated_name;
        }

        std::vector<std::string_view> GetDisplayNameCandidates(
            const std::string& preferred_language = "en",
            bool include_alt_text = false,
            bool include_obfuscated = false,
            bool include_truncated = false) const
        {
            std::vector<std::string_view> result;
            auto append_if_not_empty = [&](const std::string& s) {
                if (!s.empty()) result.push_back(s);
                };

            auto it = localized_names.find(preferred_language);
            if (it == localized_names.end() && preferred_language != "en") {
                it = localized_names.find("en");
            }
            if (it != localized_names.end()) {
                for (const auto& ln : it->second) {
                    if (!ln.name.empty()) result.push_back(ln.name);
                }
            }

            append_if_not_empty(primary_key);

            if (include_alt_text) append_if_not_empty(GetAltTextName());
            if (include_obfuscated) append_if_not_empty(GetObfuscatedName());
            if (include_truncated) append_if_not_empty(GetTruncatedName());

            if (result.empty() && !name.empty()) {
                result.push_back(name);
            }

            return result;
        }

        std::string GetBestDisplayName(
            const std::string& preferred_language = "en",
            bool include_alt_text = false,
            bool include_obfuscated = false,
            bool include_truncated = false) const
        {
            auto candidates = GetDisplayNameCandidates(preferred_language, include_alt_text, include_obfuscated, include_truncated);
            if (!candidates.empty()) {
                return std::string(candidates.front());
            }
            return "[Localization Unavailable]";
        }

        friend std::ostream& operator<<(std::ostream& os, const NameSet& names) {
            os << "NameSet{name: \"" << names.name
                << "\", external_key: \"" << names.external_key
                << "\", primary: \"" << names.primary_key
                << "\", alt_text: \"" << names.alt_text_name
                << "\", obfuscated: \"" << names.obfuscated_name
                << "\", truncated: \"" << names.truncated_name
                << "\", synonyms: [";
            for (const auto& syn : names.synonyms) {
                os << "\"" << syn << "\", ";
            }
            os << "], localized_names: [";
            for (const auto& [lang, vec] : names.localized_names) {
                os << lang << ": [";
                for (const auto& ln : vec) {
                    os << "{name: \"" << ln.name << "\", charset: \"" << ln.charset << "\"}, ";
                }
                os << "], ";
            }
            os << "]}";
            return os;
        }
    };

} // namespace ecoscore::language
