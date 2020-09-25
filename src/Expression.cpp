#include "Expression.h"

double Number::evaluate() const
{
    return value;
}

double BinaryOperation::evaluate() const
{
    double l = left->evaluate();
    double r = right->evaluate();
    double ret = 0;
    switch (op)
    {
    case '+':
        ret = l + r;
        break;
    case '*':
        ret = l * r;
        break;
    case '-':
        ret = l - r;
        break;
    case '/':
        ret = l / r;
        break;
    default:
        break;
    }
    return ret;
}

void testExpression()
{
    // ������� ������ ������� ��� ������������ 4.5 * 5
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // ����� ���������� ��� � ��������� ��� +
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);

    // ��������� � ������� ���������: 25.5
    std::cout << expr->evaluate() << std::endl;

    // ��� ������������� *���* ���������� �������
    // (��������, sube ����� ������ ��������� expr, ������� ��� ������� �� �����)
    delete expr;
}

bool check_equals(Expression const *left, Expression const *right)
{
    // put your code here
    void *ptrLeft = (void *)left;
    void *ptrRight = (void *)right;
    int memLeft = *(int *)(ptrLeft);
    int memRight = *(int *)(ptrRight);
    if ( memLeft == memRight )
    {
        return true;
    }
    return false;
}

void test_equals()
{
    Number *num1 =  new Number(5);
    Number *num2 = new Number(1);
    BinaryOperation *bin1 = new BinaryOperation(num2, '+', num1);
    std::cout << sizeof(Number) << std::endl;
    std::cout << sizeof(BinaryOperation) << std::endl;
    std::cout << check_equals(num1, bin1) << std::endl;
    std::cout << check_equals(num1, num2) << std::endl;
}
