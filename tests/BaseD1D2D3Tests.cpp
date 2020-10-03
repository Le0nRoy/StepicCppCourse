//
// Created by lap on 9/30/20.
//

#include "gtest/gtest.h"
#include "headers/BaseD1D2D3.h"

#define SUITE_NAME BaseD1D2D3Tests

TEST(SUITE_NAME, BaseD1D2D3Test) {
    stepic::D1 *d1 = new stepic::D3();
    stepic::Base *baseD1 = (stepic::Base *)(d1);

    const stepic::Base *d2 = stepic::D1BaseToD2Base(d1);

    EXPECT_TRUE((const stepic::D2 *)(d2) != nullptr);
}
