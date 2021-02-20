#pragma once
#include "GeomObject.h"


#ifndef PR_LAB4_CISOSCELESTRAPEZIUM_H
#define PR_LAB4_CISOSCELESTRAPEZIUM_H


class CIsoscelesTrapezium: public GeomObject
{
private:
    double m_mass{};
    CVector2D m_point1{};
    CVector2D m_point2{};
    CVector2D m_point3{};
    CVector2D m_point4{};
public:
    CIsoscelesTrapezium();
    CIsoscelesTrapezium(CVector2D, CVector2D, CVector2D, CVector2D);
    double get_upper_base() const;
    double get_bottom_base() const;
    double get_side() const;
    double get_square() override;
    double get_perimeter() override;
    void draw() override;
    void initFromDialog() override;
    const char* get_classname() override;
    unsigned int get_size() override;
    double get_mass() const override;
    CVector2D get_position() const override;
    bool operator== (const IPhysObject &ob) const override;
    bool operator< (const IPhysObject &ob) const override;
    ~CIsoscelesTrapezium();
};


#endif //PR_LAB4_CISOSCELESTRAPEZIUM_H
