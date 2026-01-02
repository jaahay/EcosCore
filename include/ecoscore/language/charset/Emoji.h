// File: ecoscore/language/charset/Emoji.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_EMOJI_H_
#define ECOSCORE_LANGUAGE_CHARSET_EMOJI_H_

#include "Charset.h"

namespace ecoscore::language::charset {

    /**
     * @brief Emoji character set.
     */
    struct Emoji final : ecoscore::category::Member<Emoji, ecoscore::language::Charset> {
        friend ecoscore::category::Member<Emoji, ecoscore::language::Charset>;

    private:
        constexpr Emoji() noexcept = default;
        ~Emoji() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Emoji"; }

        static constexpr const Emoji& instance() noexcept {
            static const Emoji inst{};
            return inst;
        }
    };

    inline constexpr const Emoji& emoji = Emoji::instance();

} // namespace ecoscore::language::charset

#endif // ECOSCORE_LANGUAGE_CHARSET_EMOJI_H_
