// tests/EcosCore/BasicUnitTest.cpp

#include <gtest/gtest.h>

#include "EcosCore/state/TemplateType.h"
#include "EcosCore/state/BaseType.h"
#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/EventCallback.h"
#include "EcosCore/event/PhaseTagsState.h"
#include "EcosCore/event/DefaultPriorityTags.h"
#include "EcosCore/event/PriorityTags.h"
#include "EcosCore/event/CallbackResult.h"
#include "EcosCore/event/EventContext.h"

using namespace ecoscore::state;
using namespace ecoscore::event;

using ecoscore::state::operator==;
using ecoscore::state::operator!=;
using ecoscore::state::operator<=>;

// Priority States
struct TestPriorityHigh : TemplateType<TestPriorityHigh, Priority> {
private:
    TestPriorityHigh() = default;
public:
    static const TestPriorityHigh& instance() {
        static TestPriorityHigh inst;
        return inst;
    }
    constexpr static constexpr NameSet names() const noexcept { return "TestPriorityHigh"; }
    void print(std::ostream& os) const noexcept override { os << name(); }
};

struct TestPriorityLow : TemplateType<TestPriorityLow, Priority> {
private:
    TestPriorityLow() = default;
public:
    static const TestPriorityLow& instance() {
        static TestPriorityLow inst;
        return inst;
    }
    constexpr static constexpr NameSet names() const noexcept { return "TestPriorityLow"; }
    void print(std::ostream& os) const noexcept override { os << name(); }
};

struct TestEvent : Event {};

// Tests

TEST(CoreSystem, SingletonStateIdentity) {
    const BaseType& p1a = TestPriorityHigh::instance();
    const BaseType& p1b = TestPriorityHigh::instance();
    const BaseType& p2 = TestPriorityLow::instance();

    EXPECT_EQ(&p1a, &p1b);
    EXPECT_NE(&p1a, &p2);

    EXPECT_FALSE(p1a == p2);
    EXPECT_TRUE(p1a != p2);
}

TEST(CoreSystem, PriorityOrdering) {
    const BaseType& high = TestPriorityHigh::instance();
    const BaseType& low = TestPriorityLow::instance();

    auto cmp = high <=> low;

    EXPECT_NE(cmp, std::strong_ordering::equal);
    EXPECT_TRUE(cmp == std::strong_ordering::less || cmp == std::strong_ordering::greater);
}

TEST(CoreSystem, EventDispatchOrderWithContext) {
    EventDispatcher dispatcher;
    std::vector<std::string> calls;

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext&) { calls.push_back("BeforeLow"); },
        BeforePhase::instance(),
        TestPriorityLow::instance()
    );

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext&) { calls.push_back("BeforeHigh"); },
        BeforePhase::instance(),
        TestPriorityHigh::instance()
    );

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext&) { calls.push_back("MainDefault"); },
        MainPhase::instance(),
        DefaultPriority::instance()
    );

    TestEvent event;
    dispatcher.Dispatch(event);

    ASSERT_EQ(calls.size(), 3u);
    EXPECT_EQ(calls[0], "BeforeHigh");
    EXPECT_EQ(calls[1], "BeforeLow");
    EXPECT_EQ(calls[2], "MainDefault");
}

TEST(CoreSystem, EventDispatchStopsPropagation) {
    EventDispatcher dispatcher;
    std::vector<std::string> calls;

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext& ctx) -> bool {
            calls.push_back("BeforeHigh");
            ctx.Cancel();
            return true;
        },
        BeforePhase::instance(),
        TestPriorityHigh::instance()
    );

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext&) -> bool {
            calls.push_back("BeforeLow");
            return false;
        },
        BeforePhase::instance(),
        TestPriorityLow::instance()
    );

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext&) -> bool {
            calls.push_back("MainDefault");
            return false;
        },
        MainPhase::instance(),
        DefaultPriority::instance()
    );

    TestEvent event;
    dispatcher.Dispatch(event);

    ASSERT_EQ(calls.size(), 1u);
    EXPECT_EQ(calls[0], "BeforeHigh");
}

TEST(CoreSystem, EventDispatchSkipPhase) {
    EventDispatcher dispatcher;
    std::vector<std::string> calls;

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext& ctx) {
            calls.push_back("BeforeHigh");
            ctx.SkipPhase();
        },
        BeforePhase::instance(),
        TestPriorityHigh::instance()
    );

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext&) {
            calls.push_back("BeforeLow");
        },
        BeforePhase::instance(),
        TestPriorityLow::instance()
    );

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&, EventContext&) {
            calls.push_back("MainDefault");
        },
        MainPhase::instance(),
        DefaultPriority::instance()
    );

    TestEvent event;
    dispatcher.Dispatch(event);

    ASSERT_EQ(calls.size(), 2u);
    EXPECT_EQ(calls[0], "BeforeHigh");
    EXPECT_EQ(calls[1], "MainDefault");
}
