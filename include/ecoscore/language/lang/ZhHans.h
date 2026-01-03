// File: ecoscore/language/charset/Zh_hans.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_ZH_HANS_H_
#define ECOSCORE_LANGUAGE_CHARSET_ZH_HANS_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Charset.h"

namespace ecoscore::language::charset {

    /**
     * @brief Zh_hans character set.
     */
    struct Zh_hans final : ecoscore::category::Member<Zh_hans, Charset> {
        friend ecoscore::category::Member<Zh_hans, Charset>;

    private:
        constexpr Zh_hans() noexcept = default;
        ~Zh_hans() noexcept = default;

        static constexpr Zh_hans create() { return Zh_hans{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Zh_hans"; }

    };

    inline constexpr const Zh_hans& zh_hans = Zh_hans::instance;

} // namespace ecoscore::language::charset

#endif // ECOSCORE_LANGUAGE_CHARSET_ZH_HANS_H_
