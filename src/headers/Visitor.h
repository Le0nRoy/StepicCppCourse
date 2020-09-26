#pragma once

#include <iostream>

struct Visitor;
struct PrintVisitor;
struct Expression;
struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const *number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const *operation) = 0;
    virtual ~Visitor() = default;
};

struct PrintVisitor : Visitor {
    void visitNumber(Number const *number) override;
    void visitBinaryOperation(BinaryOperation const *bop) override;
    ~PrintVisitor() override = default;
};

struct Expression {
    virtual double evaluate() const = 0;
    virtual void visit(Visitor *vistitor) const = 0;
    virtual ~Expression() = default;
};

struct Number : Expression {
    Number(double value) :
            value(value) {}

    ~Number() override = default;
    double evaluate() const override;

    inline double get_value() const {
        return value;
    }

    inline void visit(Visitor *visitor) const override {
        visitor->visitNumber(this);
    }

private:
    double value;
};

struct BinaryOperation : Expression {
    BinaryOperation(Expression const *left, char op, Expression const *right) :
            left(left),
            right(right),
            op(op) {}

    inline ~BinaryOperation() override {
        delete left;
        delete right;
    }

    double evaluate() const override;

    inline Expression const *get_left() const {
        return left;
    }

    inline Expression const *get_right() const {
        return right;
    }

    inline char get_op() const {
        return op;
    }

    inline void visit(Visitor *visitor) const override {
        visitor->visitBinaryOperation(this);
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};
