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

// Шаблон ValueHolder с типовым параметром T,
// должен содержать одно открытое поле data_
// типа T.
//
// В шаблоне ValueHolder должен быть определен
// конструктор от одного параметра типа T,
// который инициализирует поле data_.
//
// Шаблон ValueHolder должен реализовывать
// интерфейс ICloneable, и возвращать указатель
// на копию объекта, созданную в куче, из метода
// clone.

    template <typename T>
    struct ValueHolder {}; // дальше самостоятельно
}

#endif //STEPICCPPCOURSE_ICLONEABLE_H
