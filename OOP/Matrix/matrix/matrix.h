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

    /*
        Fields
    */

    /*
        private

        Pointer to current object
    */
    struct Matrix* pThis;

    /*
        private

        Number of rows in matrix
    */
    int rows;

    /*
        private

        Number of columns in matrix
    */
    int columns;

    /*
        private

        Pointer to matrix rows
    */
    struct Row *pRows;

    /*
        private

        Status of the execution code of the last operation on the matrix
    */
    enum STATUS_CODE lastStatusCode;

    /* public */

    /*
        Methods
    */

    /*
        public

        Access element of Matrix
    */
    FuncAt at;

    /*
        public

        Change value element of Matrix
    */
    FuncSet set;

    /*
        public

        Check if matrix is ​​square
    */
    FuncIsSquare isSquare;

    /*
        public

        Computed determinant of matrix
    */
    FuncDetMatrix det;

    /*
        public

        Create minor matrix (not number - matrix)
    */
    FuncMinorMatrix minorMatrix;

    /*
        public

        Sum of two matrix (return new matrix)
    */
    FuncSumMatrix sum;

    /*
        public

        Print matrix
    */
    FuncPrintMatrix print;

    /*
        public

        Set status code of complete last operation
    */
    FuncSetStatusCode setStatusCode;

    /*
        public

        Get status code of complete last operation
    */
    FuncGetStatusCode getStatusCode;
};

/*
    Functions for working with Matrix.
*/

/*
    public

    Matrix default constructor
*/
struct Matrix* Matrix(int, int);

/*
    public

    Matrix constructor with parameters
*/
struct Matrix* MatrixParams(int, int, TYPE_ELEM *);

/*
    public

    Matrix copy constructor
*/
struct Matrix* MatrixCopy(const struct Matrix*);

/*
    public

    Matrix by mask (zero initialization)
*/
struct Matrix* MatrixByMask(int, int, int*);

/*
    public

    Matrix by mask with values
*/
struct Matrix* MatrixByFullMask(int, int, int*, TYPE_ELEM *);

/*
    public

    Matrix destructor
*/
int DestructorMatrix(struct Matrix*);

/*
    private

    Methods initialization
*/
void methodInit(struct Matrix*);

/*
    private

    Realization Matrix::at

    Access element of Matrix
*/
TYPE_ELEM atMatrix(const struct Matrix*, int, int);

/*
    private

    Realization Matrix::set

    Change value element of Matrix
*/
void setValueElementOfMatrix(struct Matrix*, int, int, TYPE_ELEM);

/*
    private

    Realization Matrix::isSquare

    Check if matrix is ​​square
*/
int isSquareMatrix(const struct Matrix*);

/*
    private

    Realization Matrix::det

    Computed determinant of matrix
*/
TYPE_ELEM detMatrix(const struct Matrix*);

/*
    private

    Realization Matrix::minorMatrix

    Create minor matrix (not number - matrix)
*/
struct Matrix* createMinorMatrix(const struct Matrix*, int, int);

/*
    private

    Realization Matrix::sum

    Sum of two matrix (return new matrix)
*/
struct Matrix *sumMatrix(const struct Matrix *, const struct Matrix *);

/*
    private

    Realization Matrix::print

    Print matrix
*/
void printMatrix(const struct Matrix*);

/*
    private

    Realization Matrix::setStatusCode

    Set status code of complete last operation
*/
void setStatusCodeOfMatrix(struct Matrix*, enum STATUS_CODE);

/*
    private

    Realization Matrix::getStatusCode

    Get status code of complete last operation
*/
char* getStatusCodeOfMatrix(const struct Matrix*);

#undef __COMPILATION__

#endif /* __MATRIX_CLASS_H__ */