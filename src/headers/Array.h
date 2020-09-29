//
// Created by lap on 9/28/20.
//

#ifndef STEPICCPPCOURSE_ARRAY_H
#define STEPICCPPCOURSE_ARRAY_H

#include <cstddef>
#include <new>

namespace stepic {
template <typename T>
class Array {
public:
    explicit Array(size_t size = 0, const T &value = T()) :
            size_(size),
            data_(new T[size_]) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = value;
        }
    }

    Array(const Array &arr) :
            size_(arr.size_),
            data_(new T[size_]) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = arr[i];
        }
    }

    ~Array() {
        if (data_ != nullptr) {
            delete[] data_;
        }
    }

    Array &operator=(const Array &right) {
        if (this == &right) {
            return *this;
        }
        if (data_ != nullptr) {
            delete[] data_;
        }
        size_ = right.size_;
        data_ = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = right[i];
        }
        return *this;
    }

    size_t size() const {
        return size_;
    }

    T &operator[](size_t i) {
        return data_[i];
    }

    const T &operator[](size_t i) const {
        return data_[i];
    }

private:
    size_t size_;
    T *data_;
};

namespace without_assignment {
template <typename T>
class Array {
public:
    Array() :
            size_(0),
            data_(static_cast<T *>(operator new[](size_ * sizeof(T)))) {}

    explicit Array(size_t size, const T &value = T()) :
            size_(size),
            data_(static_cast<T *>(operator new[](size_ * sizeof(T)))) {
        for (size_t i = 0; i < size_; ++i) {
            new(data_ + i) T(value);
        }
    }

    Array(const Array &arr) :
            size_(arr.size_),
            data_(static_cast<T *>(operator new[](size_ * sizeof(T)))) {
        for (size_t i = 0; i < size_; ++i) {
            new(data_ + i) T(arr[i]);
        }
    }

    ~Array() {
        if (data_ != nullptr) {
#if (T != char && T != short && T != int && T != float && T != double)
            for (size_t i = 0; i < size_; ++i) {
                data_[i].~T();
            }
#endif
            operator delete[](data_);
        }
    }

    Array &operator=(const Array &right) {
        if (this == &right) {
            return *this;
        }
        if (data_ != nullptr) {
            operator delete[](data_);
        }
        size_ = right.size_;
        data_ = static_cast<T *>(operator new[](size_ * sizeof(T)));
        for (size_t i = 0; i < size_; ++i) {
            new(data_ + i) T(right[i]);
        }
        return *this;
    }

    size_t size() const {
        return size_;
    }

    T &operator[](size_t i) {
        return data_[i];
    }

    const T &operator[](size_t i) const {
        return data_[i];
    }

private:
    size_t size_;
    T *data_;

};
}
}

#endif //STEPICCPPCOURSE_ARRAY_H
