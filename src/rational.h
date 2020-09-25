//
// Created by lap on 9/24/20.
//

#ifndef TESTS_RATIONAL_H
#define TESTS_RATIONAL_H

#include <iostream>

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }

    Rational &operator+=(const Rational &rat)
    {
        this->add(rat);
        return *this;
    }
    Rational &operator-=(const Rational &rat)
    {
        this->add(rat);
        return *this;
    }
    Rational &operator*=(const Rational &rat)
    {
        this->add(rat);
        return *this;
    }
    Rational &operator/=(const Rational &rat)
    {
        this->add(rat);
        return *this;
    }

    //унарный +
    friend Rational operator+(const Rational& i);
    //унарный -
    friend Rational operator-(const Rational& i);

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

    operator double() const
    {
        return this->to_double();
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(const Rational &i)
{
    return {i.numerator_, i.denominator_};
}

Rational operator-(const Rational &i)
{
    Rational ret(i.numerator_, i.denominator_);
    ret.neg();
    return ret;
}

Rational operator+(const Rational &r1, const Rational &r2)
{
    Rational ret(r1.numerator_, r1.denominator_);
    ret.add(r2);
    return r1;
}

Rational operator-(const Rational &r1, const Rational &r2)
{
    Rational ret(r1.numerator_, r1.denominator_);
    ret.sub(r2);
    return r1;
}

Rational operator*(const Rational &r1, const Rational &r2)
{
    Rational ret(r1.numerator_, r1.denominator_);
    ret.mul(r2);
    return r1;
}

Rational operator/(const Rational &r1, const Rational &r2)
{
    Rational ret(r1.numerator_, r1.denominator_);
    ret.div(r2);
    return r1;
}

bool operator==(const Rational &r1, const Rational &r2)
{
    return (r1.numerator_ * r2.denominator_ == r2.numerator_ * r1.denominator_);
}

bool operator!=(const Rational &r1, const Rational &r2)
{
    return !(r1 == r2);
}

bool operator>(const Rational &r1, const Rational &r2)
{
    return (r1.numerator_ * r2.denominator_ > r2.numerator_ * r1.denominator_);
}

bool operator<(const Rational &r1, const Rational &r2)
{
    return (r2 > r1);
}

bool operator>=(const Rational &r1, const Rational &r2)
{
    return !(r1 < r2);
}

bool operator<=(const Rational &r1, const Rational &r2)
{
    return !(r1 > r2);
}

int test_rational() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3(5);

    r1.add(r2);
    std::cout << r1.to_double() << std::endl;
    r1.sub(r2);
    std::cout << r1.to_double() << std::endl;
    r1.neg();
    std::cout << r1.to_double() << std::endl;
    r3.mul(r1);
    std::cout << r3.to_double() << std::endl;
    r3.div(r2);
    std::cout << r3.to_double() << std::endl;
}

#endif //TESTS_RATIONAL_H
