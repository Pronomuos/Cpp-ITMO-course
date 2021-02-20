#include "CIsoscelesTrapezium.h"
#include <iostream>
#include <cmath>



    CIsoscelesTrapezium::CIsoscelesTrapezium() = default;

    CIsoscelesTrapezium::CIsoscelesTrapezium (CVector2D point1, CVector2D point2, CVector2D point3, CVector2D point4) :
            m_point1 (point1), m_point2 (point2), m_point3 (point3), m_point4 (point4) {};

    double CIsoscelesTrapezium::get_upper_base() const {
        return sqrt(pow(m_point2.x - m_point1.x, 2) + pow(m_point2.y - m_point1.y, 2));
    }

    double CIsoscelesTrapezium::get_bottom_base() const {
        return sqrt(pow(m_point4.x - m_point3.x, 2) + pow(m_point4.y - m_point3.y, 2));
    }

    double CIsoscelesTrapezium::get_side() const {
        return sqrt(pow(m_point2.x - m_point1.x, 2) + pow(m_point2.y - m_point1.y, 2));
    }

    double CIsoscelesTrapezium::get_square() {
        return (get_upper_base() + get_bottom_base()) * 0.5 *
        (sqrt(pow(get_side(),2) - (pow(get_upper_base() - get_bottom_base(), 2) * 0.25)));
    }

    double CIsoscelesTrapezium::get_perimeter() {
        return get_upper_base() + get_bottom_base() + (get_side() * 2);
    }

    void CIsoscelesTrapezium::draw() {
        std::cout << "Центр массы равнобедренной трапеции находится в точке " << get_position().x << " по x и " << get_position().y << " по y.\n";
        std::cout << "Масса трапеции - " << get_mass() << ".\n";
        std::cout << "Боковые стороны, верхняя и нижняя основания трапеции равны соответственно - " << get_side() << ", "
                  << get_upper_base() << ", " << get_bottom_base() << ".\n";
        std::cout << "Память, занимаемая трапецией - " << get_size() << " байт.\n";
    }

    void CIsoscelesTrapezium::initFromDialog() {
        std::cout << "Введите координаты левой верхней вершины трапеции (x, y): ";
        std::cin >> m_point1.x >> m_point1.y;
        std::cout << "Введите координаты правой вершней вершины трапеции (x, y): ";
        std::cin >> m_point2.x >> m_point2.y;
        std::cout << "Введите координаты левой нижней вершины трапеции (x, y): ";
        std::cin >> m_point3.x >> m_point3.y;
        std::cout << "Введите координаты правой нижней вершины трапеции (x, y): ";
        std::cin >> m_point4.x >> m_point4.y;
        std::cout << "Задайте массу трапеции: ";
        std::cin >> m_mass;

    }

   const char* CIsoscelesTrapezium::get_classname() {
        return "Равнобедренная трапеция";
    }

    unsigned int CIsoscelesTrapezium::get_size() {
        return sizeof(*this);
    }

    double CIsoscelesTrapezium::get_mass() const {
        return m_mass;
    }

    CVector2D CIsoscelesTrapezium::get_position() const {
        return {(m_point1.x + m_point2.x + m_point3.x + m_point4.x) / 4.0,
                (m_point1.y + m_point2.y + m_point3.y + m_point4.y) / 4.0};
    }

    bool CIsoscelesTrapezium::operator== (const IPhysObject &ob) const {
        return ob.get_mass() == this->get_mass();
    }

    bool CIsoscelesTrapezium::operator< (const IPhysObject &ob) const {
        return ob.get_mass() < this->get_mass();
    }

    CIsoscelesTrapezium::~CIsoscelesTrapezium() = default;
