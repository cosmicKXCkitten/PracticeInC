#include <stdio.h>
#include "matrix.h"

int main(void) 
{
    TYPE_ELEM m[3][3] =
    {
        {15, 452, 32},
        {54, 15, 60},
        {76, 87, 90},
    };

    struct Matrix* matrix1 = MatrixParams(3, 3, m);
    struct Matrix* matrix2 = MatrixCopy(matrix1);    

    printf("Matrix1:\n");
    matrix1->print(matrix1);

    printf("Matrix2:\n");
    matrix2->print(matrix2);

    matrix1->at(matrix1, 1, 1);
    printf("Last status code: %s\n", matrix1->getStatusCode(matrix1));

    printf("det(Matrix1) = %.3f\n", matrix1->det(matrix1));

    DestructorMatrix(matrix1);
    DestructorMatrix(matrix2);

    int mask[3] = {3, 2, 1};

    double fullMask[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 0},
        {6, 0, 0},
    };

    struct Matrix* matrixFullMask = MatrixByFullMask(3, 3, mask, fullMask);
    printf("Matrix by full mask:\n");
    matrixFullMask->print(matrixFullMask);

    printf("det(matrixByFullMask): %.3f", matrixFullMask->det(matrixFullMask));

    DestructorMatrix(matrixFullMask);

    return 0;
}