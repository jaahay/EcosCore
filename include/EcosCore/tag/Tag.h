// include/ecoscore/tag/Tag.h
#ifndef ECOSCORE_TAG_TAG_H
#define ECOSCORE_TAG_TAG_H

#include <string_view>
#include <iostream>
#include "StructType.h"
#include "TemplateType.h"

namespace ecoscore::tag {

    /**
     * @brief Base mixin for all tag types.
     *
     * Combines polymorphic StructType and CRTP TemplateType for compile-time identity,
     * and provides singleton instance and static name.
     *
     * @tparam Derived The derived tag type.
     */
    template <typename Derived>
    struct Tag : TemplateType<Derived, StructType> {
    private:
        constexpr Tag() noexcept = default;

    public:
        /**
         * @brief Returns the singleton instance of the Derived tag.
         *
         * @return constexpr reference to the Derived instance.
         */
        static constexpr const Derived& instance() noexcept {
            static constexpr Derived inst{};
            return inst;
        }

        /**
         * @brief Returns the static name of the Derived tag.
         *
         * @return constexpr string_view name.
         */
        static constexpr std::string_view name() noexcept {
            return Derived::name();
        }

        /**
         * @brief Stream insertion operator for the tag, prints the tag name.
         *
         * @param os Output stream.
         * @param tag Tag instance.
         * @return std::ostream& Reference to the output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const Tag& tag) {
            os << tag.name();
            return os;
        }
    };

} // namespace ecoscore::tag

#endif // ECOSCORE_TAG_TAG_H
