//
// Created by lap on 9/30/20.
//

#include "gtest/gtest.h"
#include "headers/Any.h"

#define SUITE_NAME AnyTests

TEST(SUITE_NAME, EmptyConstructorTest) {
    stepic::Any empty;
}

TEST(SUITE_NAME, OneParamConstructorTest) {
    const int value = 10;
    stepic::Any i(value);
}

TEST(SUITE_NAME, CopyConstructorTest) {
    const int value = 10;
    stepic::Any i(value);
    stepic::Any i2(i);
}

TEST(SUITE_NAME, COpyFromEmptyTest) {
    stepic::Any empty;
    stepic::Any i(empty);
}

TEST(SUITE_NAME, AssignTest) {
    const int value = 10;
    stepic::Any i(value);
    stepic::Any i2;
    i2 = i;

    i2 = 0;
}

TEST(SUITE_NAME, CastTest) {
    const int value = 10;
    stepic::Any i(value);
    stepic::Any empty2;

    int *iptr = i.cast<int>();
    char *cptr = i.cast<char>();
    int *p = empty2.cast<int>();

    EXPECT_EQ(*iptr, value);
    EXPECT_EQ(cptr, nullptr);
    EXPECT_EQ(p, nullptr);
}
