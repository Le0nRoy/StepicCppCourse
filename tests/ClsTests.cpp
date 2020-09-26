//
// Created by lap on 9/25/20.
//

#include "gtest/gtest.h"
#include "headers/Cls.h"

#define SUITE_NAME ClsTest

/// sizeof(Cls) == 24

TEST(SUITE_NAME, CheckGetInteger) {
    int i_exp = 16;
    Cls cls(0, 0, i_exp);
    int i = get_i(cls);
    EXPECT_EQ(i, i_exp);
}

TEST(SUITE_NAME, CheckGetChar) {

    char c_exp = 'n';
    Cls cls(c_exp, 0, 0);
    char c = get_c(cls);
    EXPECT_EQ(c, c_exp);
}

TEST(SUITE_NAME, CheckGetDouble) {

    double d_exp = 2.5;
    Cls cls(0, d_exp, 0);
    double d = get_d(cls);
    EXPECT_EQ(d, d_exp);
}
