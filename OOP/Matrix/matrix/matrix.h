/*
    An attempt to implement OOP in the C language
    using the example of creating matrices.

    [Attention!!!] The project uses dynamic memory allocation.

    [Dangerous!!!] Please do not forget to call the destructor for each 
    instance of the matrix when working with these matrices.

    Author: Konstantin Epishin <konstantinepishinxdevs@gmail.com>
*/
#ifndef __MATRIX_CLASS_H__
#define __MATRIX_CLASS_H__

#define __COMPILATION__

// Matrix element type
#define TYPE_ELEM double

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "types.h"
#include "status_codes.h"
#include "row.h"


/*
    Struct for Matrix.
    Matrix consists of Rows.
*/
struct Matrix
{
    /* private */

    struct Matrix* pThis;

    int rows;
    int columns;
    struct Row *pRows;

    enum STATUS_CODE lastStatusCode;

    /* public */

    /*
        Functions for computed matrix
    */

    FuncAt at;
    FuncSet set;
    FuncIsSquare isSquare;
    FuncDetMatrix det;
    FuncMinorMatrix minorMatrix;

    FuncSumMatrix sum;

    FuncPrintMatrix print;
    FuncSetStatusCode setStatusCode;
    FuncGetStatusCode getStatusCode;
};

/*
    Functions for working with Matrix.
*/

// Matrix default constructor
struct Matrix* Matrix(int, int);

// Matrix constructor with parameters
struct Matrix* MatrixParams(int, int, TYPE_ELEM *);

// Matrix copy constructor
struct Matrix* MatrixCopy(const struct Matrix*);

// Matrix by mask (zero initialization)
struct Matrix* MatrixByMask(int, int, int*);

// Matrix by mask with values
struct Matrix* MatrixByFullMask(int, int, int*, TYPE_ELEM *);

// Matrix destructor
int DestructorMatrix(struct Matrix*);

// Access element of Matrix
TYPE_ELEM atMatrix(const struct Matrix*, int, int);

// Change value element of Matrix
void setValueElementOfMatrix(struct Matrix*, int, int, TYPE_ELEM);

// Check if matrix is ​​square
int isSquareMatrix(const struct Matrix*);

// Computed determinant of matrix
TYPE_ELEM detMatrix(const struct Matrix*);

// Create minor matrix (not number - matrix)
struct Matrix* createMinorMatrix(const struct Matrix*, int, int);

// Sum of two matrix (return new matrix)
struct Matrix *sumMatrix(const struct Matrix *, const struct Matrix *);

// Print matrix
void printMatrix(const struct Matrix*);

// Set status code of complete last operation
void setStatusCodeOfMatrix(struct Matrix*, enum STATUS_CODE);

// Get status code of complete last operation
char* getStatusCodeOfMatrix(const struct Matrix*);

#undef __COMPILATION__

#endif /* __MATRIX_CLASS_H__ */