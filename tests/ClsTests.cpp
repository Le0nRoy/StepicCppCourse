//
// Created by lap on 9/25/20.
//

#include "gtest/gtest.h"
#include "Cls.h"

TEST(ClsTest, CheckGetInteger) {
    int i_exp = 16;
    Cls cls(0, 0, i_exp);
    int i = get_i(cls);
    EXPECT_EQ(i, i_exp);
}