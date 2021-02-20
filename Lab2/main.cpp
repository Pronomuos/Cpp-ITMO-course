#include <iostream>
#include <vector>
#include "set.h"
#include "menu.h"

int main() {

   SetMenu menu{};

   Set set1 = menu.creatSet();
   menu.settingOptions(set1);
   Set set2 = menu.creatSet();
   menu.settingOptions(set2);
   menu.settingOptions(set1, set2);


    return 0;
}
