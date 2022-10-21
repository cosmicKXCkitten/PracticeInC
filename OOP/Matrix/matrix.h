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
#include "status_codes.h"
#include "row.h"


/*
    Struct for Matrix.
    Matrix consists of Rows.
*/
struct Matrix;
typedef TYPE_ELEM (*FuncAt) (const struct Matrix, int, int);
typedef void (*FuncSet) (struct Matrix, int, int, TYPE_ELEM);
typedef int (*FuncIsSquare) (const struct Matrix);
typedef TYPE_ELEM (*FuncDetMatrix) (const struct Matrix);
typedef void (*FuncPrintMatrix) (const struct Matrix);
typedef void (*FuncSetStatusCode) (struct Matrix, enum STATUS_CODE);
typedef enum STATUS_CODE (*FuncGetStatusCode) (const struct Matrix);
typedef struct Matrix
{
    struct Matrix* pThis;

    int rows;
    int columns;
    struct Row *pRows;

    enum STATUS_CODE lastStatusCode;
    /*
        Functions for computed matrix
    */
    FuncAt at;
    FuncSet set;
    FuncIsSquare isSquare;
    FuncDetMatrix det;

    FuncPrintMatrix print;
    FuncSetStatusCode setStatusCode;
    FuncGetStatusCode getStatusCode;
};

/*
    Functions for working with Matrix.
*/

// Matrix default constructor
struct Matrix Matrix(int, int);

// Matrix constructor with parameters
struct Matrix MatrixParams(int, int, TYPE_ELEM *);

// Matrix copy constructor
struct Matrix MatrixCopy(const struct Matrix);

// Matrix destructor
int DestructorMatrix(struct Matrix);

// Access element of Matrix
TYPE_ELEM atMatrix(const struct Matrix, int, int);

// Change value element of Matrix
void setValueElementOfMatrix(struct Matrix, int, int, TYPE_ELEM);

// Check if matrix is ​​square
int isSquareMatrix(const struct Matrix);

// Computed determinant of matrix
TYPE_ELEM detMatrix(const struct Matrix);

// Print matrix
void printMatrix(const struct Matrix);

// Set status code of complete last operation
void setStatusCodeOfMatrix(struct Matrix, enum STATUS_CODE);

// Get status code of complete last operation
enum STATUS_CODE getStatusCodeOfMatrix(const struct Matrix);

#endif