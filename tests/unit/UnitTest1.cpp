#include <gtest/gtest.h>
#include "EcosCore/state/TemplateState.h"
#include "EcosCore/state/BaseState.h"

using namespace ecoscore::state;

struct TestPriorityHigh : TemplateState<TestPriorityHigh, BaseState> {
    static const TestPriorityHigh& instance() {
        static TestPriorityHigh inst;
        return inst;
    }
};

struct TestPriorityLow : TemplateState<TestPriorityLow, BaseState> {
    static const TestPriorityLow& instance() {
        static TestPriorityLow inst;
        return inst;
    }
};

TEST(StateTest, SingletonIdentity) {
    auto& high1 = TestPriorityHigh::instance();
    auto& high2 = TestPriorityHigh::instance();
    auto& low = TestPriorityLow::instance();

    EXPECT_EQ(&high1, &high2);
    EXPECT_NE(&high1, &low);
}
