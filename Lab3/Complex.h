#pragma once
#include <iostream>

#ifndef PR_LAB3_COMPLEX_H
#define PR_LAB3_COMPLEX_H


class Complex {
private:
    double m_re;
    double m_im;
public:
    Complex(double, double);

    friend Complex operator+(const Complex&, const Complex&);

    friend Complex operator*(const Complex&, const Complex&);

    friend Complex operator*(const Complex&, double);

    friend Complex operator*(double, const Complex&);

    explicit operator double ();

    friend std::ostream& operator<<(std::ostream&, const Complex&);

};

#endif //PR_LAB3_COMPLEX_H
