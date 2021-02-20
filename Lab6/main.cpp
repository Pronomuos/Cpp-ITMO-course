#include <iostream>
#include "myAlgoritms.h"
#include "CPoint.h"
#include <vector>


template<class T>
struct isPositive {
    bool operator() (const T &var) {
        return var > 0;
    }
};

int main() {

    int arr1[6] =  {1, 2, 3, 4, 5, -6};                                                                      ///all_of test

    my_algoritms::all_of(arr1, arr1 + 6, [](int x) { return x > 0; }) ?
    std::cout << "Each element is positive" << std::endl :
    std::cout << "Not all elements are positive" << std::endl;

    std::vector<CPoint> arr_p1;
    arr_p1.reserve(5);
    for (int i = 0; i < 5; i++)
        arr_p1.emplace_back(i + 1, i * 2);

    my_algoritms::all_of(arr_p1.begin(), arr_p1.end(), [](CPoint p) { return p.get_x() >= 0 && p.get_y() >= 0; }) ?
    std::cout << "All coordinates are in the first quarter of the Cartesian coordinate system." << std::endl :
    std::cout << "Not all coordinates are in the first quarter of the Cartesian coordinate system." << std::endl;

    int arr2[5] = { 1, 2, 5, 6, 8 };

    my_algoritms::is_partitioned(arr2, arr2 + 5, [](int i) { return i % 2 == 0; }) ?          /// is_partioned test
    std::cout << "Sequence is partitioned" << std::endl :
    std::cout << "Sequence is not partitioned" << std::endl;

    std::vector<CPoint> arr_p2;
    arr_p2.reserve(5);
    for (int i = 0; i < 5; i++)
        arr_p2.emplace_back(i + 1, i * 2);

    my_algoritms::is_partitioned(arr_p2.begin(), arr_p2.end(), [](CPoint p) { return p.get_x() % 2 == 0 && p.get_y() % 2 == 0; }) ?
    std::cout << "Sequence is partitioned" << std::endl :
    std::cout << "Sequence is not partitioned" << std::endl;

    std::vector<int> arr3 = {2, 0, 3, 5, 0, 1};
    std::vector<int>::iterator it;

    it = my_algoritms::find_backward(arr3.begin(), arr3.end(), isPositive<int>());
    if (it != arr3.begin() - 1)                                                                                                    /// find_backward test
        std::cout << "There is a posotive element in the array" << std::endl;
    else
        std::cout << "There are no positive elements in the array" << std::endl;

    std::vector<CPoint> arr_p3;
    arr_p3.reserve(5);
    for (int i = 0; i < 5; i++)
        arr_p3.emplace_back(i + 1, i * 2);

    std::vector<CPoint>::iterator  iter;
    iter = my_algoritms::find_backward(arr_p3.begin(), arr_p3.end(), isPositive<CPoint>());
    if (iter != arr_p3.begin() - 1)
        std::cout << "There is a coordinate that is in the first quarter of the Cartesian coordinate system." << std::endl;
    else
        std::cout << "There are no coordinates that are in the first quarter of the Cartesian coordinate system." << std::endl;

    return 0;
}
