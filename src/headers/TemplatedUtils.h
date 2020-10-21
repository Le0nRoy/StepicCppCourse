//
// Created by lap on 9/28/20.
//

#ifndef STEPICCPPCOURSE_TEMPLATEDUTILS_H
#define STEPICCPPCOURSE_TEMPLATEDUTILS_H

/**
 * Наверное, стоило сначала дать общие понятия о том, как происходит выбор функции
на этапе компиляции:
- приоритет всегда отдается нешаблонным функциям. Если находится нешаблонная функция,
 которая удовлетворяет всем параметрам, то вызовется именно она;
- если среди нешаблонных функций не нашлось подходящей, то компилятор рассматривает
 различные перегрузки базового шаблона (base template function),
 не учитывая специализаций, и выбирает среди перегрузок;
- если какая-то из перегрузок базового шаблона подошла, то далее компилятор
 проходится по ее специализациям и выбирает среди них.

Есть даже такой интересный пример Димова-Абрахамса. Пусть мы имеем три функции:

template void foo(T) { }
template void foo(T*) { }
template<> void foo(int*) { }

При исполнении кода:
int* p;
foo(p);
будет вызвана реализация №3. Оно и понятно. Первая и вторая функции являются теми самыми base template function — перегрузками базового шаблона. Третья функция здесь является специализацией второй функции при T*==int*. При разборе компилятор выбирает для аргумента int* функцию среди перегрузок — foo(T) и foo(T*) — и выбирает ту, что принимает указатель. Затем он перебирает ее специализации и обнаруживает, что есть одна строго для int*.

Совсем другая ситуация наступает, если мы меняем вторую и третью строки местами:

template void foo(T) { }
template<> void foo(int*) { }
template void foo(T*) { }

Тогда компилятор будет трактовать функцию foo(int*) во второй строчке,
 как специализацию первой функции foo(T) для T==int*. Тем не менее,
 он все равно начнет свой выбор с перебора перегрузок.
 Перегрузки реализованы в первой и третьей строчках, и среди foo(T) и foo(T*) для foo(int*)
 компилятор выберет foo(T*) — мы же передаем указатель. Далее он попробует пройтись
 по ее специализациям, которых в нашем коде нет, и ничего не найдет. Таким образом,
 будет вызвана третья функция.
 */

#include <cstddef>
#include <ostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "Array.h"

namespace stepic {
template <class T, class U>
void copy_n(T *dst, U *src, size_t n);

template <class T, class Comparator>
T minimum(const stepic::without_assignment::Array<T> &arr, Comparator cmp);

template <class T>
void flatten(const without_assignment::Array<T> &arr, std::ostream &os);

/// \brief Copy n elements from src array to dst array.
/// Cast from U class to T class should be implemented.
template <class T, class U>
void copy_n(T *dst, U *src, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        dst[i] = static_cast<T>(src[i]);
    }
}

/// \brief Find minimum in array arr using cmp as comparator.
/// \return Minimal element from input array.
template <class T, class Comparator>
T minimum(const without_assignment::Array<T> &arr, Comparator cmp) {
    T min = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        min = cmp(min, arr[i]) ? min : arr[i];
    }
    return min;
}

/// \brief
/// \tparam T
/// \param arr
/// \param os
template <class T>
void flatten(const without_assignment::Array<T> &arr, std::ostream &os) {
    for (size_t i = 0; i < arr.size(); ++i) {
        os << arr[i] << " ";
    }
}

template <class T>
void flatten(const without_assignment::Array<without_assignment::Array<T>> &arr, std::ostream &os) {
    for (size_t i = 0; i < arr.size(); ++i) {
        flatten(arr[i], os);
    }
}

template <class T, size_t size>
size_t array_size(T (&array)[size]) {
    return size;
}

/// \brief Check if two pointers are point to same object
/// \tparam T Polymorphic class
/// \return true if p and q are pointers to same object
template <class T>
bool isSameObject(T const *p, T const *q) {
    return dynamic_cast<const void *>(p) == dynamic_cast<const void *>(q);
}

template <class T, class U>
using templateMethod = U (T::*)() const;

/// \tparam U Some value that is returned from `mptr` and can be compared with operator<
/// \param mptr Method of class `T`
/// \return `true` if value returned from call of `mptr` from `a` is less than value from `b`
template <class T, class U>
bool compare(const T &a, const T &b, templateMethod<T, U> mptr) {
    return (a.*mptr)() < (b.*mptr)();
}

void print_values(std::ostream &) {}

/// \brief Prints `value` and all `args` to `os`
template <class T, class... Args>
void print_values(std::ostream &os, T value, const Args &... args) {
    std::string typeName(typeid(value).name());
    os << typeName << ": " << value << std::endl;
    print_values(os, args...);

    // non recursive: https://en.cppreference.com/w/cpp/language/fold
//    using expander = int[];
//    (void)expander{0,
//                   (void(os<<typeid(args).name()<<" : "<<args<<"\n"), 0)...
//    };
}

template <size_t first, size_t second, class T>
auto to_pair(const T &tuple) -> decltype(std::make_pair(std::get<first>(tuple), std::get<second>(tuple))) {
    return std::make_pair(std::get<first>(tuple), std::get<second>(tuple));
}

template <class F>
void for_each_int(int *p, int *q, F f) {
    for (; p != q; ++p) {
        f(*p);
    }
}

template <class F>
int *find_if(int *p, int *q, F f) {
    for (; p != q; ++p) {
        if (f(*p)) {
            return p;
        }
    }
    return q;
}

// Напишите функцию apply, которая принимает некоторую функцию / функциональный объект,
// а так же аргументы для вызова этого объекта, и вызывает его,
// используя perfect forwarding.
template <class F, class ...Args>
auto apply(F fu, Args &&... args) -> decltype(fu(std::forward<Args>(args)...)) {
    return fu(std::forward<Args>(args)...);
}

template <class It>
size_t max_increasing_len(It p, It q) {
    size_t ret = 0;
    size_t incLength = 1;
    It pPrev = p;
    for (++p; p != q; ++p, ++pPrev) {
        if (*p > *pPrev) {
            ++incLength;
        }
        else {
            if (incLength > ret) {
                ret = incLength;
            }
            incLength = 1;
        }
    }
    if (incLength > ret) {
        ret = incLength;
    }
    return ret;
}

template <class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n) {
    if (p == q) {
        return q;
    }
    using T = typename std::iterator_traits<FwdIt>::value_type;
    size_t i = 0;
    return std::remove_if(p, q, [&i, n](T a) { return i++ == n; });
}

template <class Iterator>
size_t count_permutations(Iterator p, Iterator q) {
    using T = typename std::iterator_traits<Iterator>::value_type;
    std::vector<T> vec(p, q);
    auto it1 = vec.begin();
    auto it2 = vec.end();
    size_t res = 0;
    std::sort(it1, it2);
    do {
        if (std::adjacent_find(it1, it2) == it2) {
            ++res;
        }
    }
    while (std::next_permutation(it1, it2));
    return res;
}

// внутри do_math объекты типа T
// - копируются
// - присваиваются
// - складываются оператором +
template <class T>
void do_math() noexcept(std::is_nothrow_copy_constructible<T>() &&
                        std::is_nothrow_copy_assignable<T>() &&
                        //                        nothrow(std::declval<T &>() = std::declval<T>()) &&
                        noexcept(std::declval<T>() + std::declval<T>())) {
    // тело функции нужно оставить пустым
}

// Просто на понимание unevaluated context
// (https://en.cppreference.com/w/cpp/language/expressions#Unevaluated_expressions).
//template <class T>
//void do_math() noexcept(noexcept(T(*((T *)0)))
//                        && noexcept(*((T *)0) = *((T *)0))
//                        && noexcept(*((T *)0) + *((T *)0))) {
//
//}
}

#endif //STEPICCPPCOURSE_TEMPLATEDUTILS_H
