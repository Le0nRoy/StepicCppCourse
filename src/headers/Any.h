//
// Created by lap on 9/30/20.
//

#ifndef STEPICCPPCOURSE_ANY_H
#define STEPICCPPCOURSE_ANY_H

#include "ICloneable.h"

namespace stepic {
class Any {
public:
    Any() :
            data_(nullptr) {}

    template <class T>
    explicit Any(T val) :
            data_(new ValueHolder<T>(val)) {}

    Any(const Any &any) {
        if (any.data_ == nullptr)
        {
            data_ = nullptr;
        }
        else {
            data_ = any.data_->clone();
        }
    }

    Any &operator=(const Any &right) {
        if (this == &right) {
            return *this;
        }
        delete data_;
        if (right.data_ == nullptr)
        {
            data_ = nullptr;
        }
        else {
            data_ = right.data_->clone();
        }
        return *this;
    }

    template <class T>
    Any &operator=(const T &right) {
        delete data_;
        data_ = new ValueHolder<T>(right);
        return *this;
    }

    ~Any() {
        delete data_;
    }

    template <class T>
    T *cast() {
        ValueHolder<T> *valPtr = dynamic_cast<ValueHolder<T> *>(data_);
        if (valPtr) {
            return &valPtr->data_;
        }
        else {
            return nullptr;
        }
    }
private:
    ICloneable *data_;
};
}

#endif //STEPICCPPCOURSE_ANY_H
