//
// Created by lap on 9/25/20.
//

#ifndef STEPICCPPCOURSE_UTILS_H
#define STEPICCPPCOURSE_UTILS_H

#include <cstdint>

#define MAX(x, y, r) \
{                  \
int i0 = (x);      \
int i1 = (y);      \
int res = (i0 < i1) ? i1 : i0; \
r = res;           \
}

/// \brief Raise x in power of p
/// \return x^p
int power(int x, unsigned p);
/// \brief Get nearest log2 of num
int log2(uint64_t num);
/// \brief Recursive GCD
unsigned gcd(unsigned a, unsigned b);
/// \brief Shift array a by several elements
/// \param a Pointer to array
/// \param size Size of array
/// \param shift Value to be shifted by
void rotate(int a[], const unsigned size, int shift);
/// \brief Get length of C-style string
unsigned strlen(const char *str);
/// \brief Concatenate two strings
/// \param to String that will contain result
/// \param from String to be concatenated to result string
void strcat(char *to, const char *from);
/// \brief Find first appearance of pattern in text
/// \return Place of first appearance
int strstr(const char *text, const char *pattern);
/// \brief Resize dynamically allocated array
/// \param str Pointer to array
/// \param size Size of array
/// \param new_size New size of array
/// \return New allocated array
char *resize(const char *str, unsigned size, unsigned new_size);
/// \brief Get line from stdin
/// \return C-style string
int **transpose(const int *const *m, unsigned rows, unsigned cols);
/// \brief Transpose matrix
/// \param m Pointer to matrix (dynamically allocated)
/// \param rows number of rows
/// \param cols number of cols
/// \return pointer to transposed matrix
void swap_min(int *m[], unsigned rows, unsigned cols);
/// \brief swap 0 row and row with minimal value
/// \param m pointer to matrix
/// \param rows number of rows
/// \param cols number of cols
void checkOverload();

#endif //STEPICCPPCOURSE_UTILS_H
