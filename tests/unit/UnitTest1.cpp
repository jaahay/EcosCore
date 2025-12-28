// tests/unit/UnitTest1.cpp

#include <gtest/gtest.h>
#include "Ecoscore/state/TemplateType.h"
#include "Ecoscore/state/BaseType.h"

using namespace ecoscore::state;

struct TestPriorityHigh : TemplateType<TestPriorityHigh, BaseType> {
    static const TestPriorityHigh& instance() {
        static TestPriorityHigh inst;
        return inst;
    }
};

struct TestPriorityLow : TemplateType<TestPriorityLow, BaseType> {
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
