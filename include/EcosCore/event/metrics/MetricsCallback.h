// EcosCore/event/util/MetricsCallback.h
#ifndef ECOSCORE_EVENT_UTIL_METRICS_CALLBACK_H
#define ECOSCORE_EVENT_UTIL_METRICS_CALLBACK_H

#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"
#include "EcosCore/tag/ResultTags.h"
#include "EcosCore/event/util/IMetricsCollector.h"

#include <typeinfo>

namespace EcosCore::event::util {

    /**
     * MetricsCallback: generic callback wrapping a metrics collector.
     */
    template <typename EventT>
    class MetricsCallback {
    public:
        explicit MetricsCallback(IMetricsCollector& collector)
            : collector_(collector) {
        }

        static MetricsCallback& instance(IMetricsCollector& collector) {
            static MetricsCallback inst(collector);
            return inst;
        }

        const EcosCore::tag::Phase& Phase() const {
            return EcosCore::tag::Before::instance();
        }

        const EcosCore::tag::Priority& Priority() const {
            return EcosCore::tag::Medium::instance();
        }

        void operator()(const EventT& event, EcosCore::event::core::EventContext&) const {
            collector_.IncrementEventCount(typeid(EventT).name());
        }

    private:
        IMetricsCollector& collector_;
    };

} // namespace EcosCore::event::util

#endif // ECOSCORE_EVENT_UTIL_METRICS_CALLBACK_H
