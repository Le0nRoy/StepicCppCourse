//
// Created by lap on 9/25/20.
//

#include "headers/Rational.h"


void Rational::add(Rational rational) {
    numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
    denominator_ *= rational.denominator_;
}

void Rational::sub(Rational rational) {
    numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
    denominator_ *= rational.denominator_;
}

void Rational::mul(Rational rational) {
    numerator_ *= rational.numerator_;
    denominator_ *= rational.denominator_;
}

void Rational::div(Rational rational) {
    numerator_ *= rational.denominator_;
    denominator_ *= rational.numerator_;
}

void Rational::neg() {
    numerator_ = -numerator_;
}

double Rational::to_double() const {
    return numerator_ / (double) denominator_;
}

Rational &Rational::operator+=(const Rational &rat) {
    this->add(rat);
    return *this;
}

Rational &Rational::operator-=(const Rational &rat) {
    this->add(rat);
    return *this;
}

Rational &Rational::operator*=(const Rational &rat) {
    this->add(rat);
    return *this;
}

Rational &Rational::operator/=(const Rational &rat) {
    this->add(rat);
    return *this;
}

Rational::operator double() const {
    return this->to_double();
}

Rational operator+(const Rational &i) {
    return {i.numerator_, i.denominator_};
}

Rational operator-(const Rational &i) {
    Rational ret(i.numerator_, i.denominator_);
    ret.neg();
    return ret;
}

Rational operator+(const Rational &r1, const Rational &r2) {
    Rational ret(r1.numerator_, r1.denominator_);
    ret.add(r2);
    return r1;
}

Rational operator-(const Rational &r1, const Rational &r2) {
    Rational ret(r1.numerator_, r1.denominator_);
    ret.sub(r2);
    return r1;
}

Rational operator*(const Rational &r1, const Rational &r2) {
    Rational ret(r1.numerator_, r1.denominator_);
    ret.mul(r2);
    return r1;
}

Rational operator/(const Rational &r1, const Rational &r2) {
    Rational ret(r1.numerator_, r1.denominator_);
    ret.div(r2);
    return r1;
}

bool operator==(const Rational &r1, const Rational &r2) {
    return (r1.numerator_ * r2.denominator_ == r2.numerator_ * r1.denominator_);
}

bool operator!=(const Rational &r1, const Rational &r2) {
    return !(r1 == r2);
}

bool operator>(const Rational &r1, const Rational &r2) {
    return (r1.numerator_ * r2.denominator_ > r2.numerator_ * r1.denominator_);
}

bool operator<(const Rational &r1, const Rational &r2) {
    return (r2 > r1);
}

bool operator>=(const Rational &r1, const Rational &r2) {
    return !(r1 < r2);
}

bool operator<=(const Rational &r1, const Rational &r2) {
    return !(r1 > r2);
}

// FIXME move to unit tests
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
    return 0;
}
