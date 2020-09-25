#include "headers/Visitor.h"

void PrintVisitor::visitNumber(const Number *number) {
    /* ... */
    std::cout << number->get_value();
}

void PrintVisitor::visitBinaryOperation(const BinaryOperation *bop) {
    /* ... */
    std::cout << "( ";
    bop->get_left()->visit(this);
    std::cout << " " << bop->get_op() << " ";
    bop->get_right()->visit(this);
    std::cout << " )";
}

double Number::evaluate() const {
    return value;
}

double BinaryOperation::evaluate() const {
    double l = left->evaluate();
    double r = right->evaluate();
    double ret = 0;
    switch (op) {
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

// FIXME move to unit test
bool check_equals(Expression const *left, Expression const *right) {
    // put your code here
    void *ptrLeft = (void *)left;
    void *ptrRight = (void *)right;
    int memLeft = *(int *)(ptrLeft);
    int memRight = *(int *)(ptrRight);
    if (memLeft == memRight) {
        return true;
    }
    return false;
}

// FIXME move to unit test
void testExpression() {
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

// FIXME move to unit test
void test_equals() {
    Number *num1 = new Number(5);
    Number *num2 = new Number(1);
    BinaryOperation *bin1 = new BinaryOperation(num2, '+', num1);
    std::cout << sizeof(Number) << std::endl;
    std::cout << sizeof(BinaryOperation) << std::endl;
    std::cout << check_equals(num1, bin1) << std::endl;
    std::cout << check_equals(num1, num2) << std::endl;
}

// FIXME move to unit test
void test_visitor() {
    Visitor *visitor = new PrintVisitor();

    Number *num1 = new Number(5);
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
