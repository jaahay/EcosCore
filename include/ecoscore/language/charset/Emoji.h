// File: ecoscore/language/charset/Emoji.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_Emoji_H_
#define ECOSCORE_LANGUAGE_CHARSET_Emoji_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Charset.h"

namespace ecoscore::language::charset {

    /**
     * @brief Emoji character set.
     */
    struct Emoji final : ecoscore::category::Member<Emoji, Charset> {
        friend ecoscore::category::Member<Emoji, Charset>;

    private:
        constexpr Emoji() noexcept = default;
        ~Emoji() noexcept = default;

        static constexpr Emoji create() { return Emoji{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Emoji"; }

    };

    inline constexpr const Emoji& emoji = Emoji::instance;

} // namespace ecoscore::language::charset

#endif // ECOSCORE_LANGUAGE_CHARSET_Emoji_H_
