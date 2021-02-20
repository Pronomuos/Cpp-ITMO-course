#pragma once
#include "GeomBase.h"

#ifndef PR_LAB4_GEOMOBJECT_H
#define PR_LAB4_GEOMOBJECT_H

class GeomObject: public IGeoFig, public IPrintable, public IDialogItitiable,
                  public BaseCObject, public IPhysObject{};

#endif //PR_LAB4_GEOMOBJECT_H
