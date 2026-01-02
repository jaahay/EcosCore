// File: ecoscore/language/lang/Ja.h
#ifndef ECOSCORE_LANGUAGE_LANG_JA_H_
#define ECOSCORE_LANGUAGE_LANG_JA_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    struct Ja final : ecoscore::category::Member<Ja, ecoscore::language::Language> {
        friend ecoscore::category::Member<Ja, ecoscore::language::Language>;

    private:
        constexpr Ja() noexcept = default;
        ~Ja() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "ja"; }

        static constexpr const Ja& instance() noexcept {
            static const Ja inst{};
            return inst;
        }
    };

    inline constexpr const Ja& ja = Ja::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_JA_H_
