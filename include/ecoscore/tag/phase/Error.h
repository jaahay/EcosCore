// include/ecoscore/tag/phase/Error.h
#ifndef ECOSCORE_TAG_PHASE_ERROR_H
#define ECOSCORE_TAG_PHASE_ERROR_H

#include "ecoscore/tag/Phases.h"
#include "ecoscore/tag/concepts/Concepts.ixx"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LanguageTags.h"
#include "ecoscore/language/CharsetTags.h"
#include <string_view>

namespace ecoscore::tag::phase {

    /**
     * @brief Phase tag representing the 'Error' phase.
     */
    struct Error final : tag::Phase<Error> {
        friend tag::Category<Error>;

    protected:
        constexpr Error() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Error";
        }

        [[nodiscard]] static constexpr language::NameSet<1, 1, 3> names() noexcept {
            return language::NameSet<1, 1, 3>{
                "Error",
                    "error",
                    "error",
                    "Error phase",
                    "E****",
                    "Error",
                { {
                    { lang::en::instance(),
                      language::LocalizedNameGroup<1, 3>{
                        { { "Error", Charset::UTF8::instance() } },
                        { "fault", "fail", "bug" }
                      }
                    }
                } }
            };
        }
    };

    static_assert(concepts::Category<Error, tag::Phase>, "Error must satisfy Category concept");

}  // namespace ecoscore::tag::phase

#endif  // ECOSCORE_TAG_PHASE_ERROR_H
