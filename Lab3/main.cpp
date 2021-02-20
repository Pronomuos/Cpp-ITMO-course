#include <iostream>
#include <cmath>
#include "Complex.h"
#include "IntQueue.h"

int main() {

    IntQueue f;                               /// Задание 8
    f << 5 << 6 << 7;
    int x, y, z;
    f >> x >> y >> z;
    std::cout << x << y << z << std::endl;

    Complex c1(1,2);                       /// Задание 1
    Complex c2(3,-1);
    double num = 5.3;
    std::cout << c1 << " " << c2 << std::endl;

    c1 = c1 * c2;
    std::cout << c1 << std::endl;
    c1 = c1 + c2;
    std::cout << c1 << std::endl;
    c1 = c1 * num;
    std::cout << c1 << std::endl;
    double length;
    length = static_cast<double>(c1);
    std::cout << length << std::endl;
   return 0;
}
