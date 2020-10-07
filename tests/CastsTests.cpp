//
// Created by lap on 10/4/20.
//

#include "gtest/gtest.h"

#define SUITE_NAME CastTests

struct Number {};

struct BigInt : Number {
    BigInt(int x){}
};

struct String {
    explicit String(char const *s);
};

TEST(SUITE_NAME, StaticCastTest) {
    int a = 3.5;
    double b = 7;
    BigInt c = 100500;
    String d = static_cast<String>("Stepik");
    Number *e = &c;
    BigInt *f = static_cast<BigInt *>(e);
    void *g = f;
    BigInt *h = static_cast<BigInt *>(g);
}

TEST(SUITE_NAME, ConstCastTest) {
    int a = 27;
    int const b = 412;
    int * pa = &a;

    int const c = a;
    int d = b;
    int const * p1 = pa;
    int * const * p2 = &pa;
    int const ** p3 = const_cast<int const **>(&pa);
    int const * const * p4 = &pa;
}
