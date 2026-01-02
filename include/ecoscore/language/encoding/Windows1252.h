// File: ecoscore/language/encoding/Windows1252.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H_
#define ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H_

#include "Encoding.h"

namespace ecoscore::language::encoding {

    /**
     * @brief Windows-1252 encoding.
     */
    struct Windows1252 final : ecoscore::category::Member<Windows1252, ecoscore::language::Encoding> {
        friend ecoscore::category::Member<Windows1252, ecoscore::language::Encoding>;

    private:
        constexpr Windows1252() noexcept = default;
        ~Windows1252() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Windows1252"; }

        static constexpr const Windows1252& instance() noexcept {
            static const Windows1252 inst{};
            return inst;
        }
    };

    inline constexpr const Windows1252& windows1252 = Windows1252::instance();

} // namespace ecoscore::language::encoding

#endif // ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H_
