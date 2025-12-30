// include/ecoscore/tag/outcome/Fail.ixx
export module ecoscore.tag.outcome.Fail;

import ecoscore.tag.Outcomes;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::outcome {

    /**
     * @brief Outcome tag indicating failure.
     */
    struct Fail final : tag::Outcome<Fail> {
        friend tag::Category<Fail>;

    protected:
        constexpr Fail() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Fail";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Fail",
                    "fail",
                    "fail",
                    "Failure outcome",
                    "F***",
                    "Fail",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Fail", Charset::UTF8::instance() } },
                        { "error", "fault", "break" }
                      }
                    }
                } }
            };
        }
    };

}  // namespace ecoscore::tag::outcome
