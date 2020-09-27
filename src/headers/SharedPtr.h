//
// Created by lap on 9/26/20.
//

#ifndef STEPICCPPCOURSE_SHAREDPTR_H
#define STEPICCPPCOURSE_SHAREDPTR_H

struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr {
    explicit SharedPtr(Expression *ptr = 0) {
        ++ptrCounter;
        ptr_ = ptr;
    }

    ~SharedPtr() {
        if (--ptrCounter == 0) {
            delete ptr_;
        }
    }

    SharedPtr(const SharedPtr &sharedPtr);
    SharedPtr &operator=(const SharedPtr &sharedPtr) {
        if (this == &sharedPtr) {
            return *this;
        }
//        return <#initializer#>;
    }

    Expression *get() const {
        return ptr_;
    }

    void reset(Expression *ptr = 0) {

    }

    Expression &operator*() const {
        return *ptr_;
    }

    Expression *operator->() const {
        return ptr_;
    }

private:
    static unsigned int ptrCounter;
    Expression *ptr_;
};

unsigned int SharedPtr::ptrCounter = 0;

#endif //STEPICCPPCOURSE_SHAREDPTR_H
