// File: ecoscore/language/charset/Cyrillic.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H_
#define ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H_

#include "Charset.h"

namespace ecoscore::language::charset {

    /**
     * @brief Cyrillic character set.
     */
    struct Cyrillic final : ecoscore::category::Member<Cyrillic, ecoscore::language::Charset> {
        friend ecoscore::category::Member<Cyrillic, ecoscore::language::Charset>;

    private:
        constexpr Cyrillic() noexcept = default;
        ~Cyrillic() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Cyrillic"; }

        static constexpr const Cyrillic& instance() noexcept {
            static const Cyrillic inst{};
            return inst;
        }
    };

    inline constexpr const Cyrillic& cyrillic = Cyrillic::instance();

} // namespace ecoscore::language::charset

#endif // ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H_
