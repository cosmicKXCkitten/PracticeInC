#include <stdio.h>
#include "matrix.h"

int main(void) 
{
    TYPE_ELEM a[3][3] =
    {
        {1, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
    };

    TYPE_ELEM b[3][3] =
    {
        {2, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    struct Matrix* matrix1 = MatrixParams(3, 3, a);
    struct Matrix* matrix2 = MatrixParams(3, 3, b);

    struct Matrix* sum = matrix1->sum(matrix1, matrix2);
    
    printf("Matrix A:\n");
    matrix1->print(matrix1);

    printf("Matrix B:\n");
    matrix2->print(matrix2);

    printf("Matrix A + B:\n");
    sum->print(sum);

    struct Matrix* difference = matrix1->difference(matrix1, matrix2);

    printf("Matrix A - B:\n");
    difference->print(difference);

    printf("det(A) = %.3f", matrix1->det(matrix1));

    printf("\n%.3f\n", matrix1->at(matrix1, 0, 0));

    DestructorMatrix(matrix1);
    DestructorMatrix(matrix2);
    DestructorMatrix(sum);
    DestructorMatrix(difference);

    return 0;
}