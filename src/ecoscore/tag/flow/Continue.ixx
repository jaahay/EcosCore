// include/ecoscore/tag/flow/Continue.ixx
export module ecoscore.tag.flow.Continue;

import ecoscore.tag.Flows;
import ecoscore.language.NameSet;
import ecoscore.language.LanguageTags;
import ecoscore.language.CharsetTags;

import <string_view>;

export namespace ecoscore::tag::flow {

    /**
     * @brief Flow control tag indicating continuation.
     */
    struct Continue final : tag::Flow<Continue> {
        friend tag::Category<Continue>;

    protected:
        constexpr Continue() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Continue";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Continue",
                    "continue",
                    "continue",
                    "Continue processing",
                    "C*******",
                    "Cont...",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Continue", Charset::UTF8::instance() } },
                        { "cont", "proceed", "go on" }
                      }
                    }
                } }
            };
        }
    };

}  // namespace ecoscore::tag::flow
