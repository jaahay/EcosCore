// File: ecoscore/event/metrics/VirtualMetricsCollector.h
// EcosCore/event/util/metrics/VirtualMetricsCollector.h
#ifndef ECOSCORE_ECOSCORE_EVENT_METRICS_VIRTUALMETRICSCOLLECTOR_H
#define ECOSCORE_ECOSCORE_EVENT_METRICS_VIRTUALMETRICSCOLLECTOR_H

#include <string_view>

namespace EcosCore::event::util::metrics {

    /**
     * VirtualMetricsCollector: abstract metrics collector interface.
     */
    class VirtualMetricsCollector {
    public:
        virtual ~VirtualMetricsCollector() = default;
        virtual void IncrementEventCount(std::string_view eventTypeName) = 0;
    };

} // namespace EcosCore::event::util::metrics

#endif // ECOSCORE_ECOSCORE_EVENT_METRICS_VIRTUALMETRICSCOLLECTOR_H
