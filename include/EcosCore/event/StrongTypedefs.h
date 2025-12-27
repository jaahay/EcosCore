// EcosCore/event/StrongTypedefs.h
#ifndef ECOSCORE_EVENT_STRONG_TYPEDEFS_H
#define ECOSCORE_EVENT_STRONG_TYPEDEFS_H

#include <cstddef>
#include <type_traits>

namespace ecoscore::event {

    template <typename T, typename Tag>
    class StrongTypedef {
    public:
        explicit constexpr StrongTypedef(T value) : value_(value) {}
        constexpr T get() const { return value_; }

        // Equality operators
        constexpr bool operator==(const StrongTypedef& other) const { return value_ == other.value_; }
        constexpr bool operator!=(const StrongTypedef& other) const { return !(*this == other); }

    private:
        T value_;
    };

    struct CallbackHandleTag {};
    using CallbackHandle = StrongTypedef<std::size_t, CallbackHandleTag>;

    struct EventIDTag {};
    using EventID = StrongTypedef<std::size_t, EventIDTag>;

    struct PhaseIDTag {};
    using PhaseID = StrongTypedef<int, PhaseIDTag>;

    struct PriorityIDTag {};
    using PriorityID = StrongTypedef<int, PriorityIDTag>;

    struct CallbackGroupIDTag {};
    using CallbackGroupID = StrongTypedef<std::size_t, CallbackGroupIDTag>;

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_STRONG_TYPEDEFS_H
