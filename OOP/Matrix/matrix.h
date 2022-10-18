/*
    An attempt to implement OOP in the C language
    using the example of creating matrices.

    [Attention!!!] The project uses dynamic memory allocation.

    [Dangerous!!!] Please do not forget to call the destructor for each 
    instance of the matrix when working with these matrices.
*/
#ifndef MATRIX
#define MATRIX

// Matrix element type
#define TYPE_ELEM double

#include <stdlib.h>
#include <stdio.h>


/*
    Struct for row of matrix.

    [Attention!!!] This is a helper type - its use in user code 
    is strictly prohibited.
*/
typedef struct Row
{
    struct Row* pThis;

    int size;
    TYPE_ELEM *elements;
};

/*
    Functions for working with auxiliary type Row.
*/

// Row default constructor
struct Row Row(int);

// Row constructor with parameters
struct Row RowParams(int, TYPE_ELEM *);

// Row destructor
int DestructorRow(struct Row);

/*****************************************************************************/

/*
    Struct for Matrix.
    Matrix consists of Rows.
*/
struct Matrix;
typedef TYPE_ELEM (*FuncAt) (int, int, struct Matrix);
typedef struct Matrix
{
    struct Matrix* pThis;

    int rows;
    int columns;
    struct Row *pRows;

    /*
        Functions for computed matrix
    */
    FuncAt at;
};

/*
    Functions for working with Matrix.
*/

// Matrix default constructor
struct Matrix Matrix(int, int);

// Matrix constructor with parameters
struct Matrix MatrixParams(int, int, TYPE_ELEM *);

// Matrix destructor
int DestructorMatrix(struct Matrix);

// Access element of Matrix
TYPE_ELEM atMatrix(int, int, struct Matrix);

#endif