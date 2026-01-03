// File: ecoscore/language/lang/Ja.h
#ifndef ECOSCORE_LANGUAGE_LANG_JA_H_
#define ECOSCORE_LANGUAGE_LANG_JA_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

    /**
     * @brief Ja language.
     */
    struct Ja final : ecoscore::category::Member<Ja, Language> {
        friend ecoscore::category::Member<Ja, Language>;

    private:
        constexpr Ja() noexcept = default;
        ~Ja() noexcept = default;

        static constexpr Ja create() { return Ja{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Ja"; }

    };

    inline constexpr const Ja& ja = Ja::instance;

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_JA_H_
