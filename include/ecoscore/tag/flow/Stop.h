// include/ecoscore/tag/flow/Stop.h
#ifndef ECOSCORE_TAG_FLOW_STOP_H
#define ECOSCORE_TAG_FLOW_STOP_H

#include "ecoscore/tag/Flows.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include <string_view>

namespace ecoscore::tag::flow {

    /**
     * @brief Flow control tag indicating stop.
     */
    struct Stop final : tag::Flow<Stop> {
        friend tag::Category<Stop>;

    protected:
        constexpr Stop() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Stop";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Stop",
                    "stop",
                    "stop",
                    "Stop processing",
                    "S**",
                    "Stop",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Stop", Charset::UTF8::instance() } },
                        { "halt", "pause", "end" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Stop, tag::Flow>, "Stop must satisfy Category concept");

    using End [[maybe_unused]] = Stop;
    using Halt [[maybe_unused]] = Stop;

}  // namespace ecoscore::tag::flow

#endif  // ECOSCORE_TAG_FLOW_STOP_H
