//
// Created by lap on 9/24/20.
//

#ifndef TESTS_RATIONAL_H
#define TESTS_RATIONAL_H

#include <iostream>

struct Rational {
    Rational(int numerator = 0, int denominator = 1) :
            numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational);

    void sub(Rational rational);

    void mul(Rational rational);

    void div(Rational rational);

    void neg();

    void inv() {}

    double to_double() const;

    Rational &operator+=(const Rational &rat);
    Rational &operator-=(const Rational &rat);
    Rational &operator*=(const Rational &rat);
    Rational &operator/=(const Rational &rat);
    explicit operator double() const;

    //унарный +
    friend Rational operator+(const Rational &i);
    //унарный -
    friend Rational operator-(const Rational &i);
    friend Rational operator+(const Rational &r1, const Rational &r2);
    friend Rational operator-(const Rational &r1, const Rational &r2);
    friend Rational operator*(const Rational &r1, const Rational &r2);
    friend Rational operator/(const Rational &r1, const Rational &r2);
    friend bool operator==(const Rational &r1, const Rational &r2);
    friend bool operator!=(const Rational &r1, const Rational &r2);
    friend bool operator>(const Rational &r1, const Rational &r2);
    friend bool operator<(const Rational &r1, const Rational &r2);
    friend bool operator>=(const Rational &r1, const Rational &r2);
    friend bool operator<=(const Rational &r1, const Rational &r2);

private:
    int numerator_;
    int denominator_;
};

#endif //TESTS_RATIONAL_H
