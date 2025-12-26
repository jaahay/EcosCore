#include <gtest/gtest.h>
#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/util/MetricsCallback.h"
#include "EcosCore/state/BaseState.h"

using namespace ecoscore::event;
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
