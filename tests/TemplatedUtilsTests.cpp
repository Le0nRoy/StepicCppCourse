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

TEST(SUITE_NAME, MinimumTest) {
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

TEST(SUITE_NAME, FlattenTest) {
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

TEST(SUITE_NAME, ArraySizeTest) {
    int ints[] = {1, 2, 3, 4};
    double doubles[] = {3.14};
    int *iptr = ints;
    size_t res;

    res = stepic::array_size(ints);
    EXPECT_EQ(res, 4);
    res = stepic::array_size(doubles);
    EXPECT_EQ(res, 1);
//    stepic::array_size(iptr); // тут должна произойти ошибка компиляции
}

TEST(SUITE_NAME, CompareTest) {
    std::string s1("Elf");
    std::string s2("Archer");
    bool res;

    res = stepic::compare(s1, s2, &std::string::size);
    EXPECT_TRUE(res);
    res = stepic::compare(s1, s1, &std::string::size);
    EXPECT_FALSE(res);
}

TEST(SUITE_NAME, PrintValuesTest) {
    stepic::print_values(std::cout, 0, 3.5, "Hello");
}

TEST(SUITE_NAME, ToPairTest) {
    int i = 0;
    double d = 3.5;
    char const * c = "Hello";
    auto t = std::make_tuple(i, d, c);

    std::pair<double, char const *> p = stepic::to_pair<1,2>(t);

    EXPECT_EQ(p.first, d);
    EXPECT_STREQ(p.second, c);
}
