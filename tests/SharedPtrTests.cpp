//
// Created by lap on 9/27/20.
//

#include "gtest/gtest.h"
#include "headers/SharedPtr.h"

#define SUITE_NAME SharedPtrTests

TEST(SUITE_NAME, someTest) {
    int *arr = new int[0];
    std::cout << arr << std::endl;
    delete[] arr;
    int *ctr = new int(1);
    if (ctr != nullptr && --*ctr == 0) {
        std::cout << "loop?" << std::endl;
    }

    int i = 9;
    if (--i == 8) {
        std::cout << 8 << std::endl;
    } else {
        std::cout << 9 << std::endl;
    }
    delete ctr;
}
