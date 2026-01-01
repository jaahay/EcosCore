// /src/ecoscore/language/Translation.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_TRANSLATION_IXX__
#define __SRC_ECOSCORE_LANGUAGE_TRANSLATION_IXX__

#include "std.h"

#include "ecoscore/category/Category.h"

#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::translation {

    /**
     * @brief Base CRTP tag for translation containers.
     *
     * Provides default get() with fallback using Derived::static_name().
     *
     * @tparam Derived Concrete translation container.
     */
template <typename Derived>
        struct Translation : ecoscore::category::Category<Derived> {
        protected:
            constexpr Translation() noexcept = default;
            constexpr ~Translation() noexcept = default;

        public:
            Translation(const Translation&) = delete;
            Translation& operator=(const Translation&) = delete;

            [[nodiscard]] const NameSet& get(const ecoscore::language::Language& lang) const noexcept {
                auto const& map = static_cast<const Derived&>(*this).translations;
                auto it = map.find(&lang);
                if (it != map.end()) {
                    return it->second;
                }

                static const std::string fallback_name = std::string(Derived::static_name()) + " (translation unavailable)";
                static const ecoscore::language::NameSet fallback{ fallback_name };
                return fallback;
            }

            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }
    };


}#endif // __SRC_ECOSCORE_LANGUAGE_TRANSLATION_IXX__
