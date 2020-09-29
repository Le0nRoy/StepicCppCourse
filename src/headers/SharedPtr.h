//
// Created by lap on 9/26/20.
//

#ifndef STEPICCPPCOURSE_SHAREDPTR_H
#define STEPICCPPCOURSE_SHAREDPTR_H

#include "Expression.h"

struct Expression;
struct Number;
struct BinaryOperation;

// TODO may be done as static pointer to dynamically allocated map
//  with pointers as keys and counters as values

// FIXME got some memory leaks
struct SharedPtr {
    explicit SharedPtr(Expression *ptr = 0) :
            ptr_(ptr),
            ptrCounter(nullptr) {
        if (ptr_ != nullptr) {
            ptrCounter = new size_t(1);
        }
    }

    SharedPtr(const SharedPtr &sharedPtr) :
            ptr_(sharedPtr.ptr_),
            ptrCounter(sharedPtr.ptrCounter) {
        if (ptrCounter != nullptr) {
            ++*ptrCounter;
        }
    }

    ~SharedPtr() {
        if (ptrCounter != nullptr && --*ptrCounter == 0) {
            delete ptr_;
            delete ptrCounter;
        }
    }

    SharedPtr &operator=(const SharedPtr &right) {
        if (this == &right) {
            return *this;
        }
        if (ptrCounter != nullptr && --*ptrCounter == 0) {
            delete ptr_;
            delete ptrCounter;
        }
        if (right.ptrCounter != nullptr) {
            ++*right.ptrCounter;
        }
        ptrCounter = right.ptrCounter;
        ptr_ = right.ptr_;

        return *this;
    }

    void reset(Expression *ptr = nullptr) {
        if (ptr_ == ptr) {
            return;
        }
        if (ptrCounter != nullptr && --*ptrCounter == 0) {
            delete ptr_;
            delete ptrCounter;
        }
        ptr_ = ptr;
        if (ptr_ != nullptr) {
            ptrCounter = new size_t(1);
        }
    }

    Expression *get() const {
        return ptr_;
    }

    Expression &operator*() const {
        return *ptr_;
    }

    Expression *operator->() const {
        return ptr_;
    }

private:
    size_t *ptrCounter;
    Expression *ptr_;
};

#endif //STEPICCPPCOURSE_SHAREDPTR_H
