// examples/event/metrics/CustomMetricsExample.cpp

#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/util/MetricsCallback.h"
#include "EcosCore/event/util/IMetricsCollector.h"
#include "EcosCore/event/Event.h"
#include <iostream>
#include <unordered_map>
#include <string>

class SimpleMetricsCollector : public EcosCore::event::util::IMetricsCollector {
    std::unordered_map<std::string, size_t> counts;
public:
    void IncrementEventCount(std::string_view eventTypeName) override {
        counts[std::string(eventTypeName)]++;
        std::cout << "Incremented count for " << eventTypeName << "\n";
    }
};

struct MyEvent : EcosCore::event::Event {};

int main() {
    EcosCore::event::core::EventDispatcher dispatcher;

    SimpleMetricsCollector metricsCollector;

    dispatcher.AddCallback<MyEvent>(
        EcosCore::event::util::MetricsCallback<MyEvent>::instance(metricsCollector),
        EcosCore::tag::Before::instance(),
        EcosCore::tag::Medium::instance());

    MyEvent event;
    dispatcher.Dispatch(event, EcosCore::tag::Before::instance());

    return 0;
}
