// File: ecoscore/encoding/charset/MacRoman.h
#ifndef ECOSCORE_ENCODING_CHARSET_MacRoman_H_
#define ECOSCORE_ENCODING_CHARSET_MacRoman_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/encoding/Charset.h"

namespace ecoscore::encoding::charset {

    /**
     * @brief MacRoman character set.
     */
    struct MacRoman final : ecoscore::category::Member<MacRoman, Charset> {
        friend ecoscore::category::Member<MacRoman, Charset>;

    private:
        constexpr MacRoman() noexcept = default;
        ~MacRoman() noexcept = default;

        static constexpr MacRoman create() { return MacRoman{}; }
    public:
        static constexpr std::string_view name() noexcept { return "MacRoman"; }

    };

    inline constexpr const MacRoman& mac_roman = MacRoman::instance;

} // namespace ecoscore::encoding::charset

#endif // ECOSCORE_ENCODING_CHARSET_MacRoman_H_
