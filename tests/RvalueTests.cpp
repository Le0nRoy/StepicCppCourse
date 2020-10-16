//
// Created by lap on 10/12/20.
//

#include "gtest/gtest.h"
#include "headers/Array.h"

#define SUITE_NAME RvalueTests

typedef stepic::Array<int> Array;

static Array &fun1(Array &s) {
    return s;
}

// Move constructor is called only when ret value is temporary parameter
static Array &&fun2(Array &s) {
    return std::move(s);
}

// Move constructor is called after std::move function
// Ret value is being formed by move constructor, but function returns by value, not ref.
static Array fun3(Array &s) {
    return std::move(s);
}

// Move constructor is called after std::move function
// Ret value is being formed by move constructor, but function returns by value, not ref.
static Array fun4(Array s) {
    return std::move(s);
}

// Move constructor is called after std::forward function
// Ret value is being formed by move constructor, but function returns by value, not ref.
// FIXME but not sure - std::forward gets value by lvalue-ref
static Array fun5(Array s) {
    return std::forward<Array>(s);
}

// Move constructor is called only when ret value is temporary parameter
static Array &&fun6(Array &&s) {
    return std::move(s);
}

static Array fun7(Array &&s) {
    return s;
}

TEST(SUITE_NAME, RvalueTest) {
    Array str;
    // 2,3,4,5,6 - move constructor
    Array str1(fun1(str));
    Array str2(fun2(str));
    Array str3(fun3(str));
    Array str4(fun4(str));
    Array str5(fun5(str));
    Array str6(fun6(std::move(str)));
    Array str7(fun7(std::move(str)));

    // 3,4,5 - move constructor
    fun1(str);
    fun2(str);
    fun3(str);
    fun4(str);
    fun5(str);
    fun6(std::move(str));
    fun7(std::move(str));
}