// File: ecoscore/callback/core/internal_fallback/InternalFallbackCallbacks.h
// EcosCore/event/core/internal_fallbacks/InternalFallbackCallbacks.h
#ifndef ECOSCORE_CALLBACK_CORE_INTERNAL_FALLBACK_INTERNALFALLBACKCALLBACKS_H
#define ECOSCORE_CALLBACK_CORE_INTERNAL_FALLBACK_INTERNALFALLBACKCALLBACKS_H

#include "EcosCore/event/Event.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/event/util/ConsoleMetricsReporter.h"
#include "EcosCore/event/util/SimpleConsoleSerializer.h"
#include "EcosCore/event/util/SteadyClockTimer.h"

#include <iostream>
#include <atomic>

namespace EcosCore::event::core::internal_fallbacks {

    inline util::ConsoleMetricsReporter& metricsCollector() {
        static util::ConsoleMetricsReporter instance;
        return instance;
} // namespace EcosCore::event::core::internal_fallbacks

    inline util::SimpleConsoleSerializer& serializer() {
        static util::SimpleConsoleSerializer instance;
        return instance;
    }

    inline util::SteadyClockTimer& timer() {
        static util::SteadyClockTimer instance;
        return instance;
    }

    /**
     * Logs when event dispatch is stopped early.
     */
    inline void LoggingFallback(const EcosCore::event::Event& event, const EcosCore::event::core::EventContext& ctx) {
        serializer().Serialize(typeid(event).name(), &event);
        std::cerr << "[Fallback] Event dispatch stopped early for event type: "
            << typeid(event).name() << "\n";
    }

    /**
     * Counts events that were dropped or stopped.
     */
    inline void MetricsFallback(const EcosCore::event::Event& /*event*/, const EcosCore::event::core::EventContext& /*ctx*/) {
        static std::atomic<size_t> dropped_events_count{ 0 };
        dropped_events_count.fetch_add(1, std::memory_order_relaxed);
        metricsCollector().IncrementEventCount("DroppedEvents");
    }

    /**
     * Cancels event if not already canceled.
     */
    inline void DefaultCancellationFallback(const EcosCore::event::Event& /*event*/, EcosCore::event::core::EventContext& ctx) {
        if (!ctx.IsCanceled()) {
            ctx.Cancel();
        }
    }

} // namespace EcosCore::event::core::internal_fallbacks

#endif // ECOSCORE_CALLBACK_CORE_INTERNAL_FALLBACK_INTERNALFALLBACKCALLBACKS_H
