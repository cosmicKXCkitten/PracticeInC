#include <stdio.h>
#include "matrix.h"

int main(void) 
{
    TYPE_ELEM m[3][3] =
    {
        {0.04, 0.05, 0.06},
        {0.07, 0.08, 0.09},
        {0.10, 0.11, 0.12},
    };

    struct Matrix matrix = MatrixParams(3, 3, m);

    TYPE_ELEM a = matrix.at(1, 1, matrix);

    printf("a = %.3f\n", a);

    DestructorMatrix(matrix);

    return 0;
}