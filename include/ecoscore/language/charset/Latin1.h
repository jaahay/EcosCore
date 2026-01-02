// File: ecoscore/language/charset/Latin1.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_LATIN1_H_
#define ECOSCORE_LANGUAGE_CHARSET_LATIN1_H_

#include "Charset.h"

namespace ecoscore::language::charset {

    /**
     * @brief Latin1 character set.
     */
    struct Latin1 final : ecoscore::category::Member<Latin1, ecoscore::language::Charset> {
        friend ecoscore::category::Member<Latin1, ecoscore::language::Charset>;

    private:
        constexpr Latin1() noexcept = default;
        ~Latin1() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Latin1"; }

        static constexpr const Latin1& instance() noexcept {
            static const Latin1 inst{};
            return inst;
        }
    };

    inline constexpr const Latin1& latin1 = Latin1::instance();

} // namespace ecoscore::language::charset

#endif // ECOSCORE_LANGUAGE_CHARSET_LATIN1_H_
