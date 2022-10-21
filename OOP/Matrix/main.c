#include <stdio.h>
#include "matrix.h"

int main(void) 
{
    TYPE_ELEM m[3][3] =
    {
        {1, 2, 3},
        {4, 4, 0.09},
        {0.10, 0.11, 0.12},
    };

    struct Matrix matrix = MatrixParams(2, 2, m);

    TYPE_ELEM a = matrix.at(matrix, 0, 0);

    printf("determinant = %.3f\n", matrix.det(matrix));

    matrix.print(matrix);

    DestructorMatrix(matrix);

    return 0;
}