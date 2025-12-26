#include <gtest/gtest.h>
#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/state/BaseState.h"

using namespace ecoscore::event;
using namespace ecoscore::state;

struct TestEvent : Event {};

TEST(EventSystem, LoggingCallbackRuns) {
    EventDispatcher dispatcher;
    bool called = false;

    dispatcher.AddCallback<TestEvent>(
        [&called](const TestEvent&, EventContext&) {
            called = true;
        },
        BeforePhase::instance(),
        DefaultPriority::instance()
    );

    TestEvent event;
    dispatcher.Dispatch(event);

    EXPECT_TRUE(called);
}
