// tests/EcosCore/BasicUnitTest.cpp
#include <gtest/gtest.h>

#include "EcosCore/state/TemplateState.h"
#include "EcosCore/state/BaseState.h"
#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/EventCallback.h"
#include "EcosCore/event/CallbackPhaseState.h"
#include "EcosCore/event/DefaultPriorityState.h"
#include "EcosCore/event/PriorityState.h"

using namespace ecoscore::state;
using namespace ecoscore::event;

struct TestPriorityHigh : TemplateState<TestPriorityHigh, PriorityState> {
private:
    TestPriorityHigh() = default;
public:
    static const TestPriorityHigh& instance() {
        static TestPriorityHigh inst;
        return inst;
    }
    constexpr std::string_view name() const noexcept { return "TestPriorityHigh"; }
    void print(std::ostream& os) const noexcept override { os << name(); }
};

struct TestPriorityLow : TemplateState<TestPriorityLow, PriorityState> {
private:
    TestPriorityLow() = default;
public:
    static const TestPriorityLow& instance() {
        static TestPriorityLow inst;
        return inst;
    }
    constexpr std::string_view name() const noexcept { return "TestPriorityLow"; }
    void print(std::ostream& os) const noexcept override { os << name(); }
};

struct TestEvent : Event {};

TEST(CoreSystem, SingletonStateIdentity) {
    auto& p1a = TestPriorityHigh::instance();
    auto& p1b = TestPriorityHigh::instance();
    auto& p2 = TestPriorityLow::instance();

    EXPECT_EQ(&p1a, &p1b);
    EXPECT_NE(&p1a, &p2);
    EXPECT_FALSE(p1a == p2);
    EXPECT_TRUE(p1a != p2);
}

TEST(CoreSystem, PriorityOrdering) {
    auto& high = TestPriorityHigh::instance();
    auto& low = TestPriorityLow::instance();

    auto cmp = high <=> low;
    EXPECT_TRUE(cmp != std::strong_ordering::equal);
}

TEST(CoreSystem, EventDispatchOrder) {
    EventDispatcher dispatcher;

    std::vector<std::string> calls;

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&) { calls.push_back("BeforeLow"); },
        BeforePhase::instance(),
        TestPriorityLow::instance()
    );

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&) { calls.push_back("BeforeHigh"); },
        BeforePhase::instance(),
        TestPriorityHigh::instance()
    );

    dispatcher.AddCallback<TestEvent>(
        [&calls](const TestEvent&) { calls.push_back("MainDefault"); },
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
