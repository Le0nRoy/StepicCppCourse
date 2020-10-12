//
// Created by lap on 10/12/20.
//

#include "gtest/gtest.h"
#include "headers/Point.h"

#define SUITE_NAME PointTests

TEST(SUITE_NAME, ScalarMultiplyTest) {
    constexpr size_t size = static_cast<size_t>(stepic::Point(2,4) * stepic::Point(4,3));
    int m[size]; // массив из 20 элементов
    EXPECT_EQ(size, 20);
}

TEST(SUITE_NAME, PlusTest) {
    constexpr stepic::Point point1(2, 4);
    constexpr stepic::Point point2(3, 5);
    constexpr stepic::Point point3 = point1 + point2;
    EXPECT_EQ(point3.x, point1.x + point2.x);
    EXPECT_EQ(point3.y, point1.y + point2.y);
}

TEST(SUITE_NAME, MinusTest) {
    constexpr stepic::Point point1(2, 4);
    constexpr stepic::Point point2(3, 5);
    constexpr stepic::Point point3 = point1 - point2;
    EXPECT_EQ(point3.x, point1.x - point2.x);
    EXPECT_EQ(point3.y, point1.y - point2.y);
}
