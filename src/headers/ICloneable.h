//
// Created by lap on 9/28/20.
//

#ifndef STEPICCPPCOURSE_ICLONEABLE_H
#define STEPICCPPCOURSE_ICLONEABLE_H

namespace stepic {
struct ICloneable {
    virtual ICloneable *clone() const = 0;

    virtual ~ICloneable() {}
};

template <typename T>
struct ValueHolder : public ICloneable {
    T data_;

    explicit ValueHolder(const T &data) :
            data_(data) {}

    ICloneable *clone() const override {
        return new ValueHolder<T>(data_);
    }
};
}

#endif //STEPICCPPCOURSE_ICLONEABLE_H
