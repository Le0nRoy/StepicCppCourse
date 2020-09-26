//
// Created by lap on 9/26/20.
//

#include "gtest/gtest.h"
#include "headers/String.h"

#define SUITE_NAME StringTests

TEST(SUITE_NAME, StringAppendTest) {
    String s1("Hello,");
    String s2(" world!");
    s1.append(s2);
    EXPECT_STREQ(s1.getStr(), "Hello, world!");
}

TEST(SUITE_NAME, SelfAppendTest) {
    String s("Hello");
    s.append(s);
    EXPECT_STREQ(s.getStr(), "HelloHello");
}

TEST(SUITE_NAME, CopyConstructorTest) {
    String str1(0, 'n');
    String str2 = str1;
    EXPECT_STREQ(str1.getStr(), str2.getStr());
    str2 = str2;
    EXPECT_STREQ(str1.getStr(), str2.getStr());
}

TEST(SUITE_NAME, AtTest) {
    String greet("Hello");
    char ch1 = greet.at(0);
//    char ch1_exp = greet.getStr()[0];
    char ch1_exp = 'H';
    EXPECT_EQ(ch1, ch1_exp);
}

TEST(SUITE_NAME, ConstAtTest) {
    String const const_greet("Hello, Const!");
    char const &const_ch1 = const_greet.at(0);
//    char const const_ch1_exp = const_greet.getStr()[0];
    char const const_ch1_exp = 'H';
    EXPECT_EQ(const_ch1, const_ch1_exp);
}
