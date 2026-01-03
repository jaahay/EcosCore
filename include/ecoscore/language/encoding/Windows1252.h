// File: ecoscore/language/encoding/Windows1252.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_Windows1252_H_
#define ECOSCORE_LANGUAGE_ENCODING_Windows1252_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Encoding.h"

namespace ecoscore::language::encoding {

    /**
     * @brief Windows1252 character set.
     */
    struct Windows1252 final : ecoscore::category::Member<Windows1252, Encoding> {
        friend ecoscore::category::Member<Windows1252, Encoding>;

    private:
        constexpr Windows1252() noexcept = default;
        ~Windows1252() noexcept = default;

        static constexpr Windows1252 create() { return Windows1252{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Windows1252"; }

    };

    inline constexpr const Windows1252& windows1252 = Windows1252::instance;

} // namespace ecoscore::language::encoding

#endif // ECOSCORE_LANGUAGE_ENCODING_Windows1252_H_
