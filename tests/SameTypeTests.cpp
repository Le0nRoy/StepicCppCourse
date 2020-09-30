//
// Created by lap on 9/30/20.
//

#include "gtest/gtest.h"
#include "headers/SameType.h"

#define SUITE_NAME SameTypeTests

TEST(SUITE_NAME, SameTypeTest) {
    bool res;

    res = stepic::SameType<int, int>::value;
    EXPECT_TRUE(res);
    res = stepic::SameType<int, int&>::value;
    EXPECT_FALSE(res);
    res = stepic::SameType<int, double>::value;
    EXPECT_FALSE(res);
}
