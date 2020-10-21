//
// Created by lap on 10/20/20.
//

#include "gtest/gtest.h"
#include "headers/FromString.h"

#define SUITE_NAME FromStringTests

TEST(SUITE_NAME, IntTest) {
    const size_t numOfTests = 3;
    struct {
        int val[numOfTests] = {
                123,
                1,
                -1
        };
    } testData;

    std::string testString;
    int resInt;
    double resDouble;
    std::string resString;

    for (int &i : testData.val) {
        testString = std::to_string(i);

        EXPECT_NO_THROW(resInt = stepic::from_string<int>(testString));
        EXPECT_NO_THROW(resDouble = stepic::from_string<double>(testString));
        EXPECT_NO_THROW(resString = stepic::from_string<std::string>(testString));

        EXPECT_EQ(resInt, i);
        EXPECT_EQ(resDouble, (double)i);
        EXPECT_STREQ(resString.data(), testString.data());
    }
}

TEST(SUITE_NAME, CharTest) {
    const size_t numOfTests = 3;
    struct {
        std::string testString[numOfTests] = {
                "1",
                " ",
                "a"
        };

        char val[numOfTests] = {
                '1',
                ' ',
                'a'
        };
    } testData;

    char resChar;

    for (size_t i = 0; i < numOfTests; ++i) {
        EXPECT_NO_THROW(resChar = stepic::from_string<char>(testData.testString[i]))
                            << " at i = " << i;
        EXPECT_EQ(resChar, testData.val[i]);
    }
}

TEST(SUITE_NAME, DoubleTest) {
    const size_t numOfTests = 4;
    struct {
        double val[numOfTests] = {
                12.3,
                1.0,
                0,
                -14
        };
    } testData;

    std::string testString;
    double resDouble;
    std::string resString;

    for (double &i : testData.val) {
        testString = std::to_string(i);

        EXPECT_NO_THROW(resDouble = stepic::from_string<double>(testString))
                            << " at i = " << i;
        EXPECT_NO_THROW(resString = stepic::from_string<std::string>(testString))
                            << " at i = " << i;

        EXPECT_THROW(stepic::from_string<char>(testString), stepic::bad_from_string);
        EXPECT_THROW(stepic::from_string<int>(testString), stepic::bad_from_string);
        EXPECT_EQ(resDouble, i);
        EXPECT_STREQ(resString.data(), testString.data());
    }
}

TEST(SUITE_NAME, StringTest) {
    const size_t numOfTests = 1;
    struct {
        std::string val[numOfTests] = {
                "abc",
        };
    } testData;

    std::string resString;

    for (auto &i : testData.val) {
        EXPECT_NO_THROW(resString = stepic::from_string<std::string>(i));

        EXPECT_THROW(stepic::from_string<char>(i), stepic::bad_from_string);
        EXPECT_THROW(stepic::from_string<int>(i), stepic::bad_from_string);
        EXPECT_THROW(stepic::from_string<double>(i), stepic::bad_from_string);
        EXPECT_STREQ(resString.data(), i.data());
    }
}

TEST(SUITE_NAME, EmptyOrSpacesStringTest) {
    const size_t numOfTests = 4;
    struct {
        std::string val[numOfTests] = {
                " 123",
                "123 ",
                "1 23",
                "",
        };
    } testData;

    for (const auto &i : testData.val) {
        EXPECT_THROW(stepic::from_string<char>(i), stepic::bad_from_string);
        EXPECT_THROW(stepic::from_string<int>(i), stepic::bad_from_string);
        EXPECT_THROW(stepic::from_string<double>(i), stepic::bad_from_string);
        EXPECT_THROW(stepic::from_string<std::string>(i), stepic::bad_from_string);
    }
}
