#include <iostream>
#include "StaticArray.h"

template <typename T>
void swap (T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5;                                                   ///Вариант С
    int b = 10;
    swap(a, b);
    std::cout << a << " " << b << std::endl;

    double d1 = 1.3;
    double d2 = 2.7;
    swap(d1, d2);
    std::cout << d1 << " " << d2 << std::endl;

    StaticArray<int, 10> arr;                                   ///Вариант F
    try
    {
        arr[100] = 20;
    }
    catch (std::exception &exception)
    {
        std::cerr << "An array exception occurred (" << exception.what() << ")\n";

    }
   std::cout << arr[0] << std::endl;


  return 0;
}
