// File: ecoscore/language/lang/Ar.h
#ifndef ECOSCORE_LANGUAGE_LANG_AR_H_
#define ECOSCORE_LANGUAGE_LANG_AR_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

    /**
     * @brief Ar language.
     */
    struct Ar final : ecoscore::category::Member<Ar, Language> {
        friend ecoscore::category::Member<Ar, Language>;

    private:
        constexpr Ar() noexcept = default;
        ~Ar() noexcept = default;

        static constexpr Ar create() { return Ar{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Ar"; }

    };

    inline constexpr const Ar& ar = Ar::instance;

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_AR_H_
