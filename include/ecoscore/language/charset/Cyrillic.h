// File: ecoscore/language/charset/Cyrillic.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_Cyrillic_H_
#define ECOSCORE_LANGUAGE_CHARSET_Cyrillic_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Charset.h"

namespace ecoscore::language::charset {

    /**
     * @brief Cyrillic character set.
     */
    struct Cyrillic final : ecoscore::category::Member<Cyrillic, Charset> {
        friend ecoscore::category::Member<Cyrillic, Charset>;

    private:
        constexpr Cyrillic() noexcept = default;
        ~Cyrillic() noexcept = default;

        static constexpr Cyrillic create() { return Cyrillic{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Cyrillic"; }

    };

    inline constexpr const Cyrillic& cyrillic = Cyrillic::instance;

} // namespace ecoscore::language::charset

#endif // ECOSCORE_LANGUAGE_CHARSET_Cyrillic_H_
