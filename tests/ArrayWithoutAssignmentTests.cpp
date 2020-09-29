//
// Created by lap on 9/29/20.
//

#include "gtest/gtest.h"
#include "headers/Array.h"
#include "headers/Expression.h"

#define SUITE_NAME ArrayWithoutAssignmentTests

TEST(SUITE_NAME, DefaultConstructorTest) {
    stepic::without_assignment::Array<int> arr;
    ASSERT_EQ(arr.size(), 0);
}

TEST(SUITE_NAME, SignedSimpleTypeTest) {
    stepic::without_assignment::Array<signed long int> arr;
    ASSERT_EQ(arr.size(), 0);
}

TEST(SUITE_NAME, ArrayIntTest) {
    size_t counter;
    size_t size = 10;
    int value = 123;
    stepic::without_assignment::Array<int> arr(size, value);

    ASSERT_EQ(arr.size(), size);
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], value) << "Error on element: " << counter;
    }

    stepic::without_assignment::Array<int> arrCopy(arr);
    ASSERT_EQ(arr.size(), arrCopy.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrCopy[counter]) << "Error on element: " << counter;
    }

    stepic::without_assignment::Array<int> arrAssignment;
    arrAssignment = arr;
    ASSERT_EQ(arr.size(), arrAssignment.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrAssignment[counter]) << "Error on element: " << counter;
    }
}

TEST(SUITE_NAME, ArrayDoubleTest) {
    size_t counter;
    size_t size = 10;
    double value = 123.0;
    stepic::without_assignment::Array<double> arr(size, value);

    ASSERT_EQ(arr.size(), size);
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], value) << "Error on element: " << counter;
    }

    stepic::without_assignment::Array<double> arrCopy(arr);
    ASSERT_EQ(arr.size(), arrCopy.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrCopy[counter]) << "Error on element: " << counter;
    }

    stepic::without_assignment::Array<double> arrAssignment;
    arrAssignment = arr;
    ASSERT_EQ(arr.size(), arrAssignment.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrAssignment[counter]) << "Error on element: " << counter;
    }
}

TEST(SUITE_NAME, ArrayStringTest) {
    size_t counter;
    size_t size = 10;
    std::string value = "123.0";
    stepic::without_assignment::Array<std::string> arr(size, value);

    ASSERT_EQ(arr.size(), size);
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], value) << "Error on element: " << counter;
    }

    stepic::without_assignment::Array<std::string> arrCopy(arr);
    ASSERT_EQ(arr.size(), arrCopy.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrCopy[counter]) << "Error on element: " << counter;
    }

    stepic::without_assignment::Array<std::string> arrAssignment;
    arrAssignment = arr;
    ASSERT_EQ(arr.size(), arrAssignment.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrAssignment[counter]) << "Error on element: " << counter;
    }
}

TEST(SUITE_NAME, ElementWithoutDefaultConstructor) {
    size_t counter;
    size_t size = 10;
    Number value = 123;
    stepic::without_assignment::Array<Number> arr(size, value);

    ASSERT_EQ(arr.size(), size);
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter].get_value(), value.get_value()) << "Error on element: " << counter;
    }

    stepic::without_assignment::Array<Number> arrCopy(arr);
    ASSERT_EQ(arr.size(), arrCopy.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter].get_value(), arrCopy[counter].get_value()) << "Error on element: " << counter;
    }

    stepic::without_assignment::Array<Number> arrAssignment;
    arrAssignment = arr;
    ASSERT_EQ(arr.size(), arrAssignment.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter].get_value(), arrAssignment[counter].get_value()) << "Error on element: " << counter;
    }
}
