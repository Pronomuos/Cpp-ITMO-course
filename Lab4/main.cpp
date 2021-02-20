#include <iostream>
#include "GeomSystem.h"

int main() {

    GeomSystem system;
    system.createObject();
    system.createObject();
    system.drawGeomSystem();
    system.totalSize();
    system.massCenter();
    system.totalSquare();
    system.totalPerimeter();
    system.sortByMass();
    system.drawGeomSystem();

    return 0;
}
