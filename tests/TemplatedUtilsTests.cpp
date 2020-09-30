//
// Created by lap on 9/30/20.
//

#include "gtest/gtest.h"
#include "headers/TemplatedUtils.h"

#define SUITE_NAME TemplatedUtilsTests

TEST(SUITE_NAME, CopyNTest) {
    const size_t arraySize = 4;
    int ints[] = {1, 2, 3, 4};
    double expectedDoubles[] = {1.0, 2.0, 3.0, 4.0};
    double doubles[arraySize] = {};

    stepic::copy_n(doubles, ints, arraySize);

    for (size_t i = 0; i < arraySize; ++i) {
        EXPECT_EQ(doubles[i], expectedDoubles[i]);
    }
}

TEST(SUITE_NAME, MinimumTests) {
    const size_t size = 5;
    int min = 44;
    int values[] = {999, min, 302, 512, 201};
    stepic::without_assignment::Array<int> array(size);

    for (size_t i = 0; i < size; ++i) {
        array[i] = values[i];
    }

    int res = stepic::minimum(array, [](int a, int b) -> bool{
        return a < b;
    });

    EXPECT_EQ(res, min);
}

TEST(SUITE_NAME, FlattenTests) {
    typedef stepic::without_assignment::Array<int> ArrayInt;
    const size_t size = 5;
    int min = 44;
    int values[] = {999, min, 302, 512, 201};
    ArrayInt array(size);

    for (size_t i = 0; i < size; ++i) {
        array[i] = values[i];
    }

    stepic::flatten(array, std::cout);

    stepic::without_assignment::Array<ArrayInt> arrOfArrs(size, array);
    stepic::flatten(arrOfArrs, std::cout);
}
