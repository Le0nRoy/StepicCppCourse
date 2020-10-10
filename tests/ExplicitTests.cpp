//
// Created by lap on 10/10/20.
//

#include "gtest/gtest.h"
#include "headers/String.h"

#define SUITE_NAME ExplicitTests

struct StringEq : public String {
    StringEq(const char *string) :
            String(string) {}

// оператор приведения к char const *
    explicit operator char const *() {
        return getStr();
    }
};

TEST(SUITE_NAME, ExplicitTest) {
    StringEq s("Hello");
    // all strings work without explicit
//    delete s;    // 1
//    if (s) { }   // 2
//    char const * p1 = s;  // 3
    char const * p2 = (char const*)s;  // 4
    char const * p3 = static_cast<char const*>(s);  // 5
//    char const * s2 = s + 4;  // 6
}
