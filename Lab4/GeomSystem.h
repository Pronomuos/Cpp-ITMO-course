#pragma once
#include "CIsoscelesTrapezium.h"
#include "CLine.h"
#include <vector>


#ifndef PR_LAB4_GEOMSYSTEM_H
#define PR_LAB4_GEOMSYSTEM_H


class GeomSystem {
private:
    std::vector<GeomObject*> m_objects;
public:
    GeomSystem();
    void createObject();
    GeomSystem& operator= (const GeomSystem&);
    void drawGeomSystem() const;
    void totalSquare() const;
    void totalPerimeter() const;
    void massCenter() const;
    void totalSize() const;
    void sortByMass();

};


#endif //PR_LAB4_GEOMSYSTEM_H
