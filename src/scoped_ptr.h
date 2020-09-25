//
// Created by lap on 9/25/20.
//

#ifndef TESTS_SCOPED_PTR_H
#define TESTS_SCOPED_PTR_H

struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr
{
    // реализуйте следующие методы:
    //
    // explicit ScopedPtr(Expression *ptr = 0)
    // ~ScopedPtr()
    // Expression* get() const
    // Expression* release()
    // void reset(Expression *ptr = 0)
    // Expression& operator*() const
    // Expression* operator->() const


private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};

#endif //TESTS_SCOPED_PTR_H
