// File: ecoscore/event/metrics/ConsoleMetricsReporter.h
// EcosCore/event/util/metrics/ConsoleMetricsReporter.h
#ifndef ECOSCORE_EVENT_METRICS_CONSOLEMETRICSREPORTER_H
#define ECOSCORE_EVENT_METRICS_CONSOLEMETRICSREPORTER_H

#include "VirtualMetricsCollector.h"
#include <atomic>
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <string_view>

namespace EcosCore::event::util::metrics {

    /**
     * ConsoleMetricsReporter: counts event occurrences and prints metrics to console.
     */
    class ConsoleMetricsReporter : public VirtualMetricsCollector {
    public:
        void IncrementEventCount(std::string_view eventTypeName) override {
            std::lock_guard lock(mutex_);
            ++event_counts_[std::string(eventTypeName)];
} // namespace EcosCore::event::util::metrics

        void PrintMetrics() const {
            std::lock_guard lock(mutex_);
            std::cout << "Event Metrics:\n";
            for (const auto& [event, count] : event_counts_) {
                std::cout << "  " << event << ": " << count << "\n";
            }
        }

    private:
        mutable std::mutex mutex_;
        std::unordered_map<std::string, size_t> event_counts_;
    };

} // namespace EcosCore::event::util::metrics

#endif // ECOSCORE_EVENT_METRICS_CONSOLEMETRICSREPORTER_H
