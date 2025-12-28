// EcosCore/tag/Tag.h
#ifndef ECOSCORE_TAG_TAG_H
#define ECOSCORE_TAG_TAG_H

#include <string_view>
#include <iostream>

namespace EcosCore::tag {

    /**
     * Base mixin for all tag types.
     * Provides singleton instance and static name.
     */
    template <typename Derived>
    struct Tag {
    private:
        constexpr Tag() noexcept = default;

    public:
        static constexpr const Derived& instance() noexcept {
            static constexpr Derived inst{};
            return inst;
        }

        static constexpr std::string_view name() noexcept {
            return Derived::name();
        }

        friend std::ostream& operator<<(std::ostream& os, const Tag& tag) {
            os << tag.name();
            return os;
        }
    };

} // namespace EcosCore::tag

#endif // ECOSCORE_TAG_TAG_H
