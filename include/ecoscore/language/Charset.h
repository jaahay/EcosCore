// File: ecoscore/language/Charset.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_H_
#define ECOSCORE_LANGUAGE_CHARSET_H_

#include "ecoscore/language/TextRepresentation.h"

namespace ecoscore::language {

    /**
     * @brief Category representing character sets.
     */
    struct Charset : TextRepresentation {
    protected:
        constexpr Charset() noexcept = default;

    public:
        Charset(const Charset&) = delete;
        Charset& operator=(const Charset&) = delete;
        ~Charset() noexcept = default;

        static constexpr std::string_view name() noexcept { return "Charset"; }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_CHARSET_H_
