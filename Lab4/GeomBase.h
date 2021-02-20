#pragma once

#ifndef PR_LAB4_GEOMBASE_H
#define PR_LAB4_GEOMBASE_H

class IGeoFig {
public:
    virtual double get_square() = 0;
    virtual double get_perimeter() = 0;
};

class CVector2D {
public:
    double x, y;
};

class IPhysObject {
public:
    virtual double get_mass() const = 0;
    virtual CVector2D get_position() const = 0;
    virtual bool operator== (const IPhysObject &ob) const = 0;
    virtual bool operator< (const IPhysObject &ob) const = 0;
};

class IPrintable {
public:
    virtual void draw() = 0;
};

class IDialogItitiable {
public:
    virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
    virtual const char* get_classname() = 0;
    virtual unsigned int get_size() = 0;
};

#endif //PR_LAB4_GEOMBASE_H
