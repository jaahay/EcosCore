// File: ecoscore/language/charset/Latin1.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_LATIN1_H_
#define ECOSCORE_LANGUAGE_CHARSET_LATIN1_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Charset.h"

namespace ecoscore::language::charset {

    /**
     * @brief Latin1 character set.
     */
    struct Latin1 final : ecoscore::category::Member<Latin1, Charset> {
        friend ecoscore::category::Member<Latin1, Charset>;

    private:
        constexpr Latin1() noexcept = default;
        ~Latin1() noexcept = default;

        static constexpr Latin1 create() { return Latin1{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Latin1"; }

    };

    inline constexpr const Latin1& latin1 = Latin1::instance;

} // namespace ecoscore::language::charset

#endif // ECOSCORE_LANGUAGE_CHARSET_LATIN1_H_
