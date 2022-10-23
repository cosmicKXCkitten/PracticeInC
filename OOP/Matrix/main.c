#include <stdio.h>
#include "matrix.h"

int main(void) 
{
    TYPE_ELEM m[3][3] =
    {
        {0.01, 0.02, 0.03},
        {0.04, 0.05, 0.06},
        {0.07, 0.08, 0.09},
    };

    struct Matrix* matrix1 = MatrixParams(2, 2, m);
    struct Matrix* matrix2 = MatrixCopy(matrix1);    

    printf("Matrix1:\n");
    matrix1->print(matrix1);

    printf("Matrix2:\n");
    matrix2->print(matrix2);

    matrix1->at(matrix1, 1, 1);
    printf("Last status code: %s", matrix1->getStatusCode(matrix1));

    DestructorMatrix(matrix1);
    DestructorMatrix(matrix2);

    return 0;
}