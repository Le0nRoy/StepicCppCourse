//
// Created by lap on 9/26/20.
//

#include "gtest/gtest.h"
#include "headers/Utils.h"

#define SUITE_NAME UtilsTests

// FIXME Add setup and teardown

TEST(SUITE_NAME, TransposeTest) {
    const int cols = 3;
    const int rows = 3;
    int row;
    int col;
//    int m[rows][cols] = {
//            {1, 2, 3},
//            {4, 5, 6},
//            {7, 8, 9}
//    };
    int **m = new int *[rows];
    for (row = 0; row < rows; ++row) {
        m[row] = new int[cols];
        for (col = 0; col < cols; ++col) {
            m[row][col] = row * cols + (col + 1);
        }
    }
    int m_exp[rows][cols] = {
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9}
    };

    int **m_res = stepic::transpose(m, rows, cols);

    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
            EXPECT_EQ(m_exp[row][col], m_res[row][col])
                                << "Difference is on row: " << row
                                << " and col: " << col;
        }
    }

    for (row = 0; row < rows; ++row) {
        delete[] m[row];
        delete[] m_res[row];
    }
    delete[] m;
    delete[] m_res;
}

TEST(SUITE_NAME, SwapMinTest) {
    const int cols = 3;
    const int rows = 3;
    int row;
    int col;
//    int m[rows][cols] = {
//            {1, 2, 3},
//            {4, 0, 6},
//            {7, 8, 9}
//    };
    int **m = new int *[rows];
    for (row = 0; row < rows; ++row) {
        m[row] = new int[cols];
        for (col = 0; col < cols; ++col) {
            m[row][col] = row * cols + (col + 1);
        }
    }
    m[1][1] = 0;
    int m_exp[rows][cols] = {
            {4, 0, 6},
            {1, 2, 3},
            {7, 8, 9}
    };

    stepic::swap_min(m, rows, cols);

    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
            EXPECT_EQ(m_exp[row][col], m[row][col])
                                << "Difference is on row: " << row
                                << " and col: " << col;
        }
    }

    for (row = 0; row < rows; ++row) {
        delete[] m[row];
    }
    delete[] m;
}
