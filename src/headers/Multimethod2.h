//
// Created by lap on 10/16/20.
//

#ifndef STEPICCPPCOURSE_MULTIMETHOD2_H
#define STEPICCPPCOURSE_MULTIMETHOD2_H

#include <typeinfo>
#include <typeindex>
#include <functional>
#include <map>
#include <stdexcept>

/// \tparam Base - базовый класс иерархии
/// \tparam Result - тип возвращаемого значения мультиметода
/// \tparam Commutative - флаг, который показывает, что мультиметод коммутативный
///     (т.е. f(x,y) = f(y,x)).
template <class Base, class Result, bool Commutative>
struct Multimethod2 {
    using Fu = std::function<Result(Base *, Base *)>;

    void addImpl(std::type_index t1, std::type_index t2, Fu f) {
        methods_.emplace(std::make_pair(t1, t2), f);
    }

    bool hasImpl(Base *a, Base *b) const {
        std::type_index t1 = typeid(*a);
        std::type_index t2 = typeid(*b);
        if ((methods_.find(std::make_pair(t1, t2)) != methods_.end()) ||
            (Commutative && methods_.find(std::make_pair(t2, t1)) != methods_.end())) {
            return true;
        }
        else {
            return false;
        }

    }

    Result call(Base *a, Base *b) const {
        std::type_index t1 = typeid(*a);
        std::type_index t2 = typeid(*b);

        Base *arg1 = a;
        Base *arg2 = b;

        auto it = methods_.find(std::make_pair(t1, t2));
        if (Commutative) {
            if (it != methods_.end()) {
                it = it;
            }
            else {
                it = methods_.find(std::make_pair(t2, t1));
                arg1 = b;
                arg2 = a;
            }
        }

        if (it == methods_.end()) {
            std::string excep("No function for such arguments is implemented. Args: ");
            excep.append(t1.name());
            excep.append(" ");
            excep.append(t2.name());
            throw std::logic_error(excep);
        }

        return it->second(arg1, arg2);
    }

private:
    std::map<std::pair<std::type_index, std::type_index>, Fu> methods_;
};

#endif //STEPICCPPCOURSE_MULTIMETHOD2_H
