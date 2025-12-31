// /src/ecoscore/language/lang/Lang.ixx
export module ecoscore.language.lang.Lang;

export import ecoscore.language.lang.en;
export import ecoscore.language.lang.fr;
export import ecoscore.language.lang.de;
export import ecoscore.language.lang.es;
export import ecoscore.language.lang.zh_hans;
export import ecoscore.language.lang.zh_hant;
export import ecoscore.language.lang.ja;
export import ecoscore.language.lang.ko;
export import ecoscore.language.lang.ar;

namespace ecoscore::language::lang {

    /**
     * @brief Facade module exporting all language tags.
     */
    struct LangDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.language.lang";
        }
    };

}
