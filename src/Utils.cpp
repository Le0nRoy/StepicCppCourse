//
// Created by lap on 9/25/20.
//

#include "headers/Utils.h"
#include <iostream>

namespace stepic {

// TODO add unit test

    int power(int x, unsigned p) {
        int answer = 1;
        while (p) {
            answer *= x;
            p--;
        }
        /* считаем answer */
        return answer;
    }

// TODO add unit test

    int log2(uint64_t num) {
        int res = 0;

        while (num > 1) {
            num = num >> 1;
            res++;
        }

        return res;
    }

// TODO add unit test

    unsigned gcd(unsigned a, unsigned b) {
        unsigned res = 1;
        // Обязательно делим большее на меньшее
        unsigned num1 = 0;
        unsigned num2 = 0;
        num1 = (a > b) ? a : b;
        num2 = (num1 == a) ? b : a;
        // Находим остаток от деления
        unsigned r = 0;
        r = num1 % num2;
        // Если остаток не равен нулю, то продолжаем
        if (r != 0) {
            res = gcd(num2, r);
        }
        else {
            res = num2;
        }
        return res;
    }

// TODO add unit test

    void rotate(int a[], const unsigned size, int shift) {
        while (shift--) {
            int buf = a[0];
            for (unsigned i = 0; i < size; i++) {
                a[i] = a[i + 1];
                if (i == size - 1) {
                    a[i] = buf;
                }
            }
        }
    }

// TODO add unit test

    unsigned strlen(const char *str) {
        int i = 0;
        while (str[i++] != '\0') {}
        i--;
        return i;
    }

// TODO add uit test

    void strcat(char *to, const char *from) {
        int count_to = 0;
        int count_from = 0;
        while (to[count_to++] != '\0') {}
        count_to--;

        while (from[count_from] != '\0') {
            to[count_to] = from[count_from];
            count_to++;
            count_from++;
        }
        to[count_to] = '\0';
        return;
    }

// TODO add unit test

    int strstr(const char *text, const char *pattern) {
        int res = 0;

        int size_text = strlen(text);
        int size_pat = strlen(pattern);
        if (size_pat == 0) {
            return 0;
        }

        if (size_text < size_pat) {
            return -1;
        }

        int count_sim = 0;
        size_t i = 0;
        for (i = 0; i < size_text; i++) {
            for (size_t j = 0; j < size_pat; j++) {
                if (*(pattern + j) == *(text + i + j)) {
                    count_sim++;
                }
                else {
                    count_sim = 0;
                    j = size_pat;
                }
            }

            if (count_sim == size_pat) {
                return i;
            }
        }

        return -1;
    }

// TODO add unit tests

    char *resize(const char *str, unsigned size, unsigned new_size) {
        char *new_ar = new char[new_size];
//    memcpy(new_ar, str, size);
        unsigned check_size = (size < new_size) ? size : new_size;
        for (unsigned i = 0; i < check_size; i++) {
            *(new_ar + i) = *(str + i);
        }
        delete[] str;


        return new_ar;
    }

    char *getline() {
        int str_size = 100;
        char *str = new char[str_size];
        char c = 0;
        int i = 0;
        while (std::cin.get(c) && c != '\n' && c != std::cin.eof()) {
            str[i] = c;
            ++i;
            if (i >= str_size) {
                int new_str_size = str_size * 2;
                str = resize(str, str_size, new_str_size);
                str_size = new_str_size;
            }
        }

        if (str[i - 1] != '\0') {
            if (i >= str_size) {
                str = resize(str, str_size, str_size + 1);
            }
            str[i] = '\0';
        }
        return str;
    }

    int **transpose(const int *const *m, unsigned rows, unsigned cols) {
        int **m_t = new int *[cols];
        for (int i = 0; i < cols; ++i) {
            m_t[i] = new int[rows];
            for (int j = 0; j < rows; ++j) {
                m_t[i][j] = m[j][i];
            }
        }
        return m_t;
    }

    void swap_min(int *m[], unsigned rows, unsigned cols) {
        int row = 0;
        for (int min = m[0][0], i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                if (m[i][j] < min) {
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

    static void foo(char) {
        std::cout << "char" << std::endl;
    }

    static void foo(signed char) {
        std::cout << "signed char" << std::endl;
    }

    static void foo(unsigned char) {
        std::cout << "unsigned char" << std::endl;
    }

    void checkOverload() {
        // Error
        //foo(97);
        // foo(char) is called
        foo('a');
    }
}
