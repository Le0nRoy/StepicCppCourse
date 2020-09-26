//
// Created by lap on 9/25/20.
//

#include "headers/Utils.h"
#include <iostream>

/// \brief Transpose matrix
/// \param m Pointer to matrix (dynamically allocated)
/// \param rows number of rows
/// \param cols number of cols
/// \return pointer to transposed matrix
int **transpose(const int *const *m, unsigned rows, unsigned cols)
{
    int **m_t = new int *[cols];
    for (int i = 0; i < cols; ++i) {
        m_t[i] = new int[rows];
        for (int j = 0; j < rows; ++j) {
            m_t[i][j] = m[j][i];
        }
    }
    return m_t;
}

/// \brief swap 0 row and row with minimal value
/// \param m pointer to matrix
/// \param rows number of rows
/// \param cols number of cols
void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int row = 0;
    for (int min = m[0][0], i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; j++)
        {
            if (m[i][j] < min)
            {
                min = m[i][j];
                row = i;
            }
        }
    }
    int *p = m[0];
    m[0] = m[row];
    m[row] = p;
}

///
/// Funtions overloading
///

static void foo(char)
{
    std::cout << "char" << std::endl;
}
static void foo(signed char)
{
    std::cout << "signed char" << std::endl;
}
static void foo(unsigned char)
{
    std::cout << "unsigned char" << std::endl;
}

void checkOverload()
{
    // Error
    //foo(97);
    // foo(char) is called
    foo('a');
}
