#include "CLine.h"
#include <iostream>
#include <cmath>


    CLine::CLine() = default;

    CLine::CLine (CVector2D point1, CVector2D point2) : m_point1(point1), m_point2(point2){}

    double CLine::get_length() {
        return sqrt(pow(m_point2.x - m_point1.x, 2) + pow(m_point2.y - m_point1.y, 2));
    }

    double CLine::get_square() {
        return get_length();
    }

    double CLine::get_perimeter()
    {
        return get_length();
    }

    void CLine::draw() {
        std::cout << "Центр массы фигуры находится в точке " << get_position().x << " по x и " << get_position().y << " по y.\n";
        std::cout << "Длина отрезка - " << get_length() << ".\n";
        std::cout << "Масса отрезка - " << get_mass() << ".\n";
        std::cout << "Память, занимаемая отрезком - " << get_size() << " байт.\n";
    }

    void CLine::initFromDialog() {
        std::cout << "Введите координаты одного конца отрезка (x, y): ";
        std::cin >> m_point1.x >> m_point1.y;
        std::cout << "Введите координаты другого конца отрезка(x, y): ";
        std::cin >> m_point2.x >> m_point2.y;
        std::cout << "Задайте массу отрезку: ";
        std::cin >> m_mass;
    }

    const char* CLine::get_classname() {
        return "Отрезок";
    }

    unsigned int CLine::get_size() {
        return sizeof(*this);
    }

    double CLine::get_mass() const {
        return m_mass;
    }

    CVector2D CLine::get_position() const {
        return {(m_point1.x + m_point2.x) / 2.0,(m_point1.y + m_point2.y) / 2.0};
    }

    bool CLine::operator== (const IPhysObject &ob) const {
        return ob.get_mass() == this->get_mass();
    }

    bool CLine::operator< (const IPhysObject &ob) const {
        return ob.get_mass() < this->get_mass();
    }

    CLine::~CLine() = default;