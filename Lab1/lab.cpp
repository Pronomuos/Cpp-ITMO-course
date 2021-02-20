#include "lab.h"

void add(int& a, int& b) {    /// Задание 2
    a+=b;
}
void add(int* a, int* b) {
    *a += *b;
}



void minus(int& a) {         /// Задание 7
    a = -a;
}
void minus(double& a) {
    a = -a;
}
void minus (int* a) {
    *a = -*a;
}
void minus (double* a) {
    *a = -*a;
}


void complex_conj(complex& num) {    /// Задание 10
    num.im_num = -num.im_num;
}
void complex_conj(complex* num) {
    num->im_num = -num->im_num;
}



void mult_matrix(double (&arr) [3][3], double num) {     /// Задание 15
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] *= num;
        }
    }
}
void mult_matrix(int (&arr) [3][3], double num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] *= num;
        }
    }
}
void mult_matrix(double (*arr) [3][3], double num) {
    for (int i = 0; i < 9; i++) {
            *(arr[0][0]+i) *= num;
    }
}
void mult_matrix(int (*arr) [3][3], double num) {
    for (int i = 0; i < 9; i++) {
        *(arr[0][0]+i) *= num;
    }
}

