//
// Created by lap on 9/28/20.
//

#include "gtest/gtest.h"
#include "headers/Array.h"

#define SUITE_NAME ArrayTests

TEST(SUITE_NAME, ArrayIntTest) {
    size_t counter;
    size_t size = 10;
    int value = 123;
    stepic::Array<int> arr(size, value);

    ASSERT_EQ(arr.size(), size);
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], value) << "Error on element: " << counter;
    }

    stepic::Array<int> arrCopy(arr);
    ASSERT_EQ(arr.size(), arrCopy.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrCopy[counter]) << "Error on element: " << counter;
    }

    stepic::Array<int> arrAssignment = arr;
    ASSERT_EQ(arr.size(), arrAssignment.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrAssignment[counter]) << "Error on element: " << counter;
    }
}

TEST(SUITE_NAME, ArrayDoubleTest) {
    size_t counter;
    size_t size = 10;
    double value = 123.0;
    stepic::Array<double> arr(size, value);

    ASSERT_EQ(arr.size(), size);
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], value) << "Error on element: " << counter;
    }

    stepic::Array<double> arrCopy(arr);
    ASSERT_EQ(arr.size(), arrCopy.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrCopy[counter]) << "Error on element: " << counter;
    }

    stepic::Array<double> arrAssignment = arr;
    ASSERT_EQ(arr.size(), arrAssignment.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrAssignment[counter]) << "Error on element: " << counter;
    }
}

TEST(SUITE_NAME, ArrayStringTest) {
    size_t counter;
    size_t size = 10;
    std::string value = "123.0";
    stepic::Array<std::string> arr(size, value);

    ASSERT_EQ(arr.size(), size);
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], value) << "Error on element: " << counter;
    }

    stepic::Array<std::string> arrCopy(arr);
    ASSERT_EQ(arr.size(), arrCopy.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrCopy[counter]) << "Error on element: " << counter;
    }

    stepic::Array<std::string> arrAssignment = arr;
    ASSERT_EQ(arr.size(), arrAssignment.size());
    for (counter = 0; counter < arr.size(); ++counter) {
        EXPECT_EQ(arr[counter], arrAssignment[counter]) << "Error on element: " << counter;
    }
}

TEST(SUITE_NAME, MoveTest) {
    size_t intArr1Size = 10;
    stepic::Array<int> intArr1(intArr1Size, 0);
    stepic::Array<int> intArr2(std::move(intArr1));
    EXPECT_EQ(intArr2.size(), intArr1Size);

    size_t intArr3Size = 15;
    stepic::Array<int> intArr3(intArr3Size, 5);
    size_t intArr4Size = 12;
    stepic::Array<int> intArr4(intArr4Size, 3);

    intArr4 = std::move(intArr3);
    EXPECT_EQ(intArr4.size(), intArr3Size);
    // This should be to avoid memory leak
    EXPECT_EQ(intArr3.size(), intArr4Size);
}
