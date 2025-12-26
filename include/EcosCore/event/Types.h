// EcosCore/event/Types.h
#ifndef ECOSCORE_EVENT_TYPES_H
#define ECOSCORE_EVENT_TYPES_H

#include <cstddef>
#include <chrono>

namespace ecoscore::event {

    using CallbackHandle = std::size_t;

    using Timestamp = std::chrono::steady_clock::time_point;
    using Duration = std::chrono::steady_clock::duration;

    // Optional aliases for future use
    using EventID = std::size_t;
    using PhaseID = int;
    using PriorityID = int;
    using CallbackGroupID = std::size_t;

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_TYPES_H
