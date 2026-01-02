// File: ecoscore/language/encoding/MacRoman.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H_
#define ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H_

#include "Encoding.h"

namespace ecoscore::language::encoding {

    /**
     * @brief MacRoman encoding.
     */
    struct MacRoman final : ecoscore::category::Member<MacRoman, ecoscore::language::Encoding> {
        friend ecoscore::category::Member<MacRoman, ecoscore::language::Encoding>;

    private:
        constexpr MacRoman() noexcept = default;
        ~MacRoman() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "MacRoman"; }

        static constexpr const MacRoman& instance() noexcept {
            static const MacRoman inst{};
            return inst;
        }
    };

    inline constexpr const MacRoman& macRoman = MacRoman::instance();

} // namespace ecoscore::language::encoding

#endif // ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H_
