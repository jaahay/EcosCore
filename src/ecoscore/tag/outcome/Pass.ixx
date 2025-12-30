// include/ecoscore/tag/outcome/Pass.ixx
export module ecoscore.tag.outcome.Pass;

import ecoscore.tag.Outcomes;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::outcome {

    /**
     * @brief Outcome tag indicating success.
     */
    struct Pass final : tag::Outcome<Pass> {
        friend tag::Category<Pass>;

    protected:
        constexpr Pass() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Pass";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Pass",
                    "pass",
                    "pass",
                    "Success outcome",
                    "P***",
                    "Pass",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Pass", Charset::UTF8::instance() } },
                        { "success", "ok", "win" }
                      }
                    }
                } }
            };
        }
    };

}  // namespace ecoscore::tag::outcome
