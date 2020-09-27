//
// Created by lap on 9/25/20.
//

#ifndef TESTS_SCOPED_PTR_H
#define TESTS_SCOPED_PTR_H

#include "Expression.h"

struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr {
    explicit ScopedPtr(Expression *ptr = 0) {
        ptr_ = ptr;
    }

    ~ScopedPtr() {
        delete ptr_;
    }

    Expression *get() const {
        return ptr_;
    }

    Expression *release() {
        Expression *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void reset(Expression *ptr = 0) {
        delete ptr_;
        ptr_ = ptr;
    }

    Expression &operator*() const {
        return *ptr_;
    }

    Expression *operator->() const {
        return ptr_;
    }

private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr &);
    ScopedPtr &operator=(const ScopedPtr &);

    Expression *ptr_;
};

#endif //TESTS_SCOPED_PTR_H
