// File: ecoscore/language/lang/Ar.h
#ifndef ECOSCORE_LANGUAGE_LANG_AR_H_
#define ECOSCORE_LANGUAGE_LANG_AR_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    struct Ar final : ecoscore::category::Member<Ar, ecoscore::language::Language> {
        friend ecoscore::category::Member<Ar, ecoscore::language::Language>;

    private:
        constexpr Ar() noexcept = default;
        ~Ar() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "ar"; }

        static constexpr const Ar& instance() noexcept {
            static const Ar inst{};
            return inst;
        }
    };

    inline constexpr const Ar& ar = Ar::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_AR_H_
