// File: ecoscore/language/encoding/UTF32.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_UTF32_H_
#define ECOSCORE_LANGUAGE_ENCODING_UTF32_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Encoding.h"

namespace ecoscore::language::encoding {

    /**
     * @brief UTF32 character set.
     */
    struct UTF32 final : ecoscore::category::Member<UTF32, Encoding> {
        friend ecoscore::category::Member<UTF32, Encoding>;

    private:
        constexpr UTF32() noexcept = default;
        ~UTF32() noexcept = default;

        static constexpr UTF32 create() { return UTF32{}; }
    public:
        static constexpr std::string_view name() noexcept { return "UTF32"; }

    };

    inline constexpr const UTF32& uTF32 = UTF32::instance;

} // namespace ecoscore::language::encoding

#endif // ECOSCORE_LANGUAGE_ENCODING_UTF32_H_
