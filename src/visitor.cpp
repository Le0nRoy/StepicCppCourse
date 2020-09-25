#include "visitor.h"

namespace ns_visitor {

void test_visitor()
{
    Visitor *visitor = new PrintVisitor();

    Number *num1 =  new Number(5);
    Number *num2 = new Number(1);
    Number *num3 = new Number(4.5);
    BinaryOperation *expr1 = new BinaryOperation(num1, '*', num2);
    BinaryOperation *expr2 = new BinaryOperation(num3, '+', expr1);

    visitor->visitNumber(num1);
    std::cout << std::endl;
    visitor->visitNumber(num2);
    std::cout << std::endl;
    visitor->visitNumber(num3);
    std::cout << std::endl;
    visitor->visitBinaryOperation(expr1);
    std::cout << std::endl;
    visitor->visitBinaryOperation(expr2);
    std::cout << std::endl;
}

}
