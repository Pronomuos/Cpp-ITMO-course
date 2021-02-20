
#ifndef PR_LAB2_MENU_H
#define PR_LAB2_MENU_H


#pragma once
#include "set.h"

class SetMenu {
public:
    SetMenu();
    Set creatSet();
    void settingOptions (Set&);
    void settingOptions (Set&, Set&);
};



#endif //PR_LAB2_MENU_H
