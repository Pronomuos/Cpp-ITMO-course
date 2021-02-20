#include "Complex.h"
#include <iostream>
#include <cmath>

    Complex::Complex(double re, double im): m_re(re), m_im(im) {}

    Complex operator+ (const Complex &c1, const Complex &c2) {

        return {c1.m_re + c2.m_re, c1.m_im + c2.m_im};
    }

    Complex operator* (const Complex &c1, const Complex &c2) {
        return {c1.m_re * c2.m_re, c1.m_im * c2.m_im};
    }

    Complex operator* (const Complex &c, double num) {

        return {c.m_re * num, c.m_im};
    }

    Complex operator* (double num, const Complex &c) {

        return {c.m_re * num, c.m_im};
    }

    Complex::operator double () {

        return sqrt(pow(m_re, 2) + pow(m_im, 2));
    }

    std::ostream& operator<< (std::ostream& out, const Complex &c) {

    out << "(" << c.m_re << ", " << c.m_im << ")";

    return out;
}