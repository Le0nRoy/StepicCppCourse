//
// Created by lap on 9/26/20.
//

#include "gtest/gtest.h"
#include "headers/Expression.h"

#define SUITE_NAME ExpressionTests

class SUITE_NAME : public ::testing::Test {
public:
    /// \brief Checks both operands are of same class
    /// \return true if same class
    static bool check_equals(Expression const *left, Expression const *right) {
        void *ptrLeft = (void *)left;
        void *ptrRight = (void *)right;
        int memLeft = *(int *)(ptrLeft);
        int memRight = *(int *)(ptrRight);
        if (memLeft == memRight) {
            return true;
        }
        return false;
    }
};

/// sizeof(Number) == 16
/// sizeof(BinaryOperation) == 32
TEST(SUITE_NAME, EqualsTest) {
    Number *num1 = new Number(5);
    Number *num2 = new Number(1);
    BinaryOperation *bin1 = new BinaryOperation(num2, '+', num1);
    EXPECT_FALSE(SUITE_NAME::check_equals(num1, bin1));
    EXPECT_TRUE(SUITE_NAME::check_equals(num1, num2));
}

TEST(SUITE_NAME, ExpressionTest) {
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);
    double exp = 25.5;

    EXPECT_DOUBLE_EQ(exp, expr->evaluate());

    delete expr;
}