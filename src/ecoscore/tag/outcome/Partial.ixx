// include/ecoscore/tag/outcome/Partial.ixx
export module ecoscore.tag.outcome.Partial;

import ecoscore.tag.Outcomes;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::outcome {

    /**
     * @brief Outcome tag indicating partial success.
     */
    struct Partial final : tag::Outcome<Partial> {
        friend tag::Category<Partial>;

    protected:
        constexpr Partial() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Partial";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Partial",
                    "partial",
                    "partial",
                    "Partial success outcome",
                    "Pa***",
                    "Partial",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Partial", Charset::UTF8::instance() } },
                        { "some", "half", "part" }
                      }
                    }
                } }
            };
        }
    };

}  // namespace ecoscore::tag::outcome
