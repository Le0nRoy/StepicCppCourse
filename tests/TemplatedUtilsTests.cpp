//
// Created by lap on 9/30/20.
//

#include <list>
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

TEST(SUITE_NAME, ForEachIntTest) {
    int m[10] = {1,2,3,4,5,6,7,8,9,10};
    int m_exp[10] = {1,4,9,16,25,36,49,64,81,100};

    // That's the task of step
    auto square_fun = [](int &num) {num = num * num;};

    stepic::for_each_int(m, m + 10, square_fun);

    for (int i = 0; i < 0; ++i) {
        EXPECT_EQ(m[i], m_exp[i]) << "Error on i: " << i;
    }
}

TEST(SUITE_NAME, FindIfTest) {
    int primes[5] = {2,3,5,7,11};
    int m[10] = {0,0,1,1,4,6,7,8,9,10};

    auto gen_finder = [](int *p, int *q){
        return [p, q](int x) -> bool {
            int *pc = p;
            if (pc == q) {
            }
            for (; pc != q; ++pc) {
                if (*pc == x) {
                    return true;
                }
            }
            return false;
        };
    };

    int * first_prime = stepic::find_if(m, m + 10, gen_finder(primes, primes + 5));

    EXPECT_EQ(*first_prime, 7);
}

TEST(SUITE_NAME, ApplyTest) {
    auto fun = [](std::string a, std::string const& b) { return a += b; };
    std::string s("world!");
// s передаётся по lvalue ссылке,
// а временный объект по rvalue ссылке
    s = stepic::apply(fun, std::string("Hello, "), s);

    EXPECT_STREQ(s.data(), "Hello, world!");
}

TEST(SUITE_NAME, MaxIncreasingLenTest) {
    std::list<int> const l1 = {7,8,9,4,5,6,1,2,3,4};
    size_t len1 = stepic::max_increasing_len(l1.begin(), l1.end());
    // 4, соответствует подотрезку 1,2,3,4
    EXPECT_EQ(len1, 4);

    std::list<int> const l2 = {-3,-2,-1,0,0,1,2,3,4,5};
    size_t len2 = stepic::max_increasing_len(l2.begin(), l2.end());
    // 6, соответствует подотрезку 0,1,2,3,4,5
    EXPECT_EQ(len2, 6);

    std::list<int> const l3 = {4,5,3};
    size_t len3 = stepic::max_increasing_len(l3.begin(), l3.end());
    // 6, соответствует подотрезку 0,1,2,3,4,5
    EXPECT_EQ(len3, 2);
}
