#pragma once
#include "GeomObject.h"

#ifndef PR_LAB4_CLINE_H
#define PR_LAB4_CLINE_H


class CLine: public GeomObject
{
private:
    double m_mass{};
    CVector2D m_point1{};
    CVector2D m_point2{};
public:
    CLine();
    CLine (CVector2D, CVector2D);
    double get_length();
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
    virtual ~CLine();
};


#endif //PR_LAB4_CLINE_H
