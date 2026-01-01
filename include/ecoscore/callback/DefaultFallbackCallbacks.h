// File: ecoscore/callback/DefaultFallbackCallbacks.h
// EcosCore/event/util/DefaultFallbackCallbacks.h
#ifndef ECOSCORE_ECOSCORE_CALLBACK_DEFAULTFALLBACKCALLBACKS_H
#define ECOSCORE_ECOSCORE_CALLBACK_DEFAULTFALLBACKCALLBACKS_H

#include "EcosCore/event/Event.h"
#include "EcosCore/event/core/EventContext.h"
#include <iostream>
#include <atomic>

namespace EcosCore::event::util {

    /**
     * Logs when event dispatch is stopped early.
     */
    inline void DefaultStopInterceptor(const EcosCore::event::Event& event, const EcosCore::event::core::EventContext& ctx) {
        std::cerr << "[Fallback] Event dispatch stopped early for event type: "
            << typeid(event).name() << "\n";
} // namespace EcosCore::event::util

    /**
     * Counts events that were dropped or stopped.
     */
    inline void DefaultMetricsInterceptor(const EcosCore::event::Event& /*event*/, const EcosCore::event::core::EventContext& /*ctx*/) {
        static std::atomic<size_t> dropped_events_count{ 0 };
        dropped_events_count.fetch_add(1, std::memory_order_relaxed);
        // Optionally expose this count for monitoring
    }

} // namespace EcosCore::event::util

#endif // ECOSCORE_ECOSCORE_CALLBACK_DEFAULTFALLBACKCALLBACKS_H
