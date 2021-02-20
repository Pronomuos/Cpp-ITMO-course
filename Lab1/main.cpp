#include <iostream>
#include "lab.h"

int main() {
    int a=1, b=2;        /// Задание 2

    int *ptr_1 = &a;
    int *ptr_2 = &b;

    add (a,b);
    std::cout << a << " " << b << std::endl;
    add(ptr_1,ptr_2);
    std::cout << a << " " << b << std::endl;


    minus(ptr_1);               /// Задание 7
    std::cout << a << std::endl;
    minus(b);
    std::cout << b << std::endl;



    complex c;                 /// Задание 10
    c.re_num = 2;
    c.im_num = 2;
    complex_conj (c);
    std::cout << "(" << c.re_num << ", " << c.im_num << ")" << std::endl;
    complex *ptr_3 = &c;
    complex_conj(ptr_3);
    std::cout << "(" << c.re_num << ", " << c.im_num << ")" << std::endl;




    double matrix_1 [3][3] = {1.00, 1.00, 1.00,   /// Задание 15
                            1.00, 1.00, 1.00,
                            1.00, 1.00, 1.00 };
    int matrix_2 [3][3] = {1, 1, 1,
                           1, 1, 1,
                           1, 1, 1 };


    mult_matrix(&matrix_1, 4.3);
    mult_matrix(matrix_1, 4.3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::cout << matrix_1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    mult_matrix(&matrix_1, 9.30);
    mult_matrix(matrix_2, 9.30);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
           std::cout << matrix_2[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
