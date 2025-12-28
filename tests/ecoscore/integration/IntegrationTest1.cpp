// tests/integration/IntegrationTest1.cpp

#include <gtest/gtest.h>
#include "Ecoscore/event/core/EventDispatcher.h"
#include "Ecoscore/event/util/MetricsCallback.h"
#include "Ecoscore/state/DefaultPriorityTags.h"

using namespace ecoscore::event::core;
using namespace ecoscore::event::util;
using namespace ecoscore::state;

struct IntegrationEvent : Event {};

TEST(EventIntegration, MetricsCountIncrements) {
    EventDispatcher dispatcher;

    dispatcher.AddCallback<IntegrationEvent>(
        MetricsCallback<IntegrationEvent>::instance(),
        AfterPhase::instance(),
        DefaultPriority::instance()
    );

    IntegrationEvent event;
    dispatcher.Dispatch(event);
    dispatcher.Dispatch(event);

    EXPECT_GE(MetricsCallback<IntegrationEvent>::instance().GetCount(), 2);
}
