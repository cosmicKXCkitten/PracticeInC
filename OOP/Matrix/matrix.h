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
#include <math.h>
#include "row.h"


/*
    Struct for Matrix.
    Matrix consists of Rows.
*/
struct Matrix;
typedef TYPE_ELEM (*FuncAt) (struct Matrix, int, int);
typedef int (*FuncIsSquare) (struct Matrix);
typedef TYPE_ELEM (*FuncDetMatrix) (struct Matrix);
typedef void (*FuncPrintMatrix) (struct Matrix);
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
    FuncIsSquare isSquare;
    FuncDetMatrix det;

    FuncPrintMatrix print;
};

/*
    Functions for working with Matrix.
*/

// Matrix default constructor
struct Matrix Matrix(int, int);

// Matrix constructor with parameters
struct Matrix MatrixParams(int, int, TYPE_ELEM *);

// Matrix copy constructor
//struct Matrix MatrixCopy(struct Matrix);

// Matrix destructor
int DestructorMatrix(struct Matrix);

// Access element of Matrix
TYPE_ELEM atMatrix(struct Matrix, int, int);

// Check if matrix is ​​square
int isSquareMatrix(struct Matrix);

// Computed determinant of matrix
TYPE_ELEM detMatrix(struct Matrix);

// Print matrix
void printMatrix(struct Matrix);

#endif