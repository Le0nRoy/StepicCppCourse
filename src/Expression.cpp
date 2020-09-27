#include "headers/Expression.h"

void PrintVisitor::visitNumber(const Number *number) {
    std::cout << number->get_value();
}

void PrintVisitor::visitBinaryOperation(const BinaryOperation *bop) {
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
