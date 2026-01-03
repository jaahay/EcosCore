// File: ecoscore/language/Encoding.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_H_
#define ECOSCORE_LANGUAGE_ENCODING_H_

#include "ecoscore/language/TextRepresentation.h"

namespace ecoscore::language {

    /**
     * @brief Category representing text encodings.
     */
    struct Encoding : TextRepresentation {
    protected:
        constexpr Encoding() noexcept = default;

    public:
        Encoding(const Encoding&) = delete;
        Encoding& operator=(const Encoding&) = delete;
        ~Encoding() noexcept = default;

        static constexpr std::string_view name() noexcept { return "Encoding"; }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_ENCODING_H_
