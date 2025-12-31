// /src/ecoscore/language/translation/Translation.ixx
export module ecoscore.language.translation.Translation;

import std;

import ecoscore.state.Category;

import ecoscore.language.NameSet;
import ecoscore.language.Languages;

namespace ecoscore::language::translation {

    /**
     * @brief Base CRTP tag for translation containers.
     *
     * Provides default get() with fallback using Derived::static_name().
     *
     * @tparam Derived Concrete translation container.
     */
    export template <typename Derived>
        struct Translation : ecoscore::state::Category<Derived> {
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
                static const NameSet fallback{ fallback_name };
                return fallback;
            }

            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }
    };

} // namespace ecoscore::language::translation
