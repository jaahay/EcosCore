// File: ecoscore/event/StrongTypedefs.h
// EcosCore/event/StrongTypedefs.h
#ifndef ECOSCORE_EVENT_STRONGTYPEDEFS_H
#define ECOSCORE_EVENT_STRONGTYPEDEFS_H

#include <cstdint>
#include <type_traits>
#include <utility>

/**
 * Strong typedef utility to create distinct types from base types.
 * Inspired by Boost.StrongTypedef.
 */
template <typename T, typename Parameter>
class StrongTypedef {
public:
    explicit constexpr StrongTypedef(const T& value) : value_(value) {}
    explicit constexpr StrongTypedef(T&& value) : value_(std::move(value)) {}

    constexpr const T& get() const noexcept { return value_; }
    constexpr T& get() noexcept { return value_; }

    constexpr explicit operator T() const noexcept { return value_; }

    // Comparison operators
    friend constexpr bool operator==(const StrongTypedef& lhs, const StrongTypedef& rhs) {
        return lhs.value_ == rhs.value_;
    }
    friend constexpr bool operator!=(const StrongTypedef& lhs, const StrongTypedef& rhs) {
        return !(lhs == rhs);
    }

private:
    T value_;
};

#endif // ECOSCORE_EVENT_STRONGTYPEDEFS_H
