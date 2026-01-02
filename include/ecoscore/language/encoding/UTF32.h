// File: ecoscore/language/encoding/UTF32.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_UTF32_H_
#define ECOSCORE_LANGUAGE_ENCODING_UTF32_H_

#include "Encoding.h"

namespace ecoscore::language::encoding {

    /**
     * @brief UTF-32 encoding.
     */
    struct UTF32 final : ecoscore::category::Member<UTF32, ecoscore::language::Encoding> {
        friend ecoscore::category::Member<UTF32, ecoscore::language::Encoding>;

    private:
        constexpr UTF32() noexcept = default;
        ~UTF32() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "UTF32"; }

        static constexpr const UTF32& instance() noexcept {
            static const UTF32 inst{};
            return inst;
        }
    };

    inline constexpr const UTF32& utf32 = UTF32::instance();

} // namespace ecoscore::language::encoding

#endif // ECOSCORE_LANGUAGE_ENCODING_UTF32_H_
