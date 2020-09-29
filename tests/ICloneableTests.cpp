//
// Created by lap on 9/30/20.
//

#include "gtest/gtest.h"
#include "headers/ICloneable.h"

#define SUITE_NAME ICloneableTests

TEST(SUITE_NAME, CloneTest) {
    std::string data("data");
    stepic::ValueHolder<std::string> val(data);

    ASSERT_EQ(val.data_, data);

    auto *copy = dynamic_cast<stepic::ValueHolder<std::string> *>(val.clone());
    EXPECT_EQ(copy->data_, data);

    delete copy;
}
