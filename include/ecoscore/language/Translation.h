// File: ecoscore/language/translation/Translation.h
#ifndef ECOSCORE_LANGUAGE_TRANSLATION_H_
#define ECOSCORE_LANGUAGE_TRANSLATION_H_

#include "ecoscore/category/Category.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/Language.h"

#include <string_view>
#include <unordered_map>

namespace ecoscore::language::translation {

    /**
     * @brief Base CRTP tag for translation containers.
     *
     * Provides final get() method with fallback logic.
     * Derived classes override NameSets() to provide translation data.
     *
     * @tparam Derived Concrete translation container.
     */
    template <typename Derived>
    struct Translation : ecoscore::category::Category {
    protected:
        constexpr Translation() noexcept = default;
        constexpr ~Translation() noexcept = default;

    public:
        Translation(const Translation&) = delete;
        Translation& operator=(const Translation&) = delete;

        /**
         * @brief Retrieve the NameSet for a given language.
         *
         * This method is final and cannot be overridden.
         * It uses the NameSets() method, which can be customized by derived classes.
         *
         * @param lang Language to get translation for.
         * @return const reference to NameSet.
         */
        [[nodiscard]] const NameSet& get(const ecoscore::language::Language& lang) const noexcept final {
            const auto& map = static_cast<const Derived&>(*this).NameSets();
            auto it = map.find(&lang);
            if (it != map.end()) {
                return it->second;
            }
            static constexpr NameSet fallback{ Derived::static_name() + " (translation unavailable)" };
            return fallback;
        }

        /**
         * @brief Returns the translation map.
         *
         * Derived classes override this to provide concrete translation data.
         * Default implementation returns a fallback map with a single entry.
         *
         * @return const reference to translation map.
         */
        [[nodiscard]] virtual const std::unordered_map<const ecoscore::language::Language*, NameSet>& NameSets() const noexcept {
            static const std::unordered_map<const ecoscore::language::Language*, NameSet> fallback{ };
            return fallback;
        }

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return Derived::static_name();
        }
    };

} // namespace ecoscore::language::translation

#endif // ECOSCORE_LANGUAGE_TRANSLATION_H_
