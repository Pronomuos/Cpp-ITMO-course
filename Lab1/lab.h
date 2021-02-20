#pragma once

#ifndef PR_LAB1_LAB_H
#define PR_LAB1_LAB_H

struct complex {
    int re_num;
    int im_num;
};

void add(int&, int&);
void add(int*, int*);

void minus(int&);
void minus(double&);
void minus (int*);
void minus (double*);

void complex_conj(complex&);
void complex_conj(complex*);


void mult_matrix(double (&arr) [3][3], double);
void mult_matrix(double (*arr) [3][3], double);
void mult_matrix(int (&arr) [3][3], double);
void mult_matrix (int (*arr) [3][3], double);



#endif //PR_LAB1_LAB_H
