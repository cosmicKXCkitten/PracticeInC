#include "matrix.h"

/*
    Implementation functions for working with rows.
*/

// Row default constructor
struct Row Row(int size) 
{
    return RowParams(size, NULL);
}

// Row constructor with parameters
struct Row RowParams(int size, TYPE_ELEM *values) 
{
    // Memory allocation for row
    struct Row* row = (struct Row*)malloc(sizeof(struct Row));

    // Initialization fields of Row
    row->pThis = row;
    row->size = size;

    // Memory allocation for array of elements
    TYPE_ELEM *elements = (TYPE_ELEM *)malloc(size * sizeof(TYPE_ELEM));

    // Initialization elements of Row
    row->elements = elements;

    if (values == NULL) 
    {
        // Zero initialization
        for (int i = 0; i < size; ++i) 
        {
            row->elements[i] = 0;
        }
    }
    else 
    {
        // Initialization by values
        for (int i = 0; i < size; ++i) 
        {
            row->elements[i] = values[i];
        } 
    }

    return *row;
}

// Row destructor
int DestructorRow(struct Row row) 
{
    // Free memory row of elements
    free(row.elements);

    // Free memory of row
    free(row.pThis);

    return 0;
}

/*****************************************************************************/

/*
    Implementation functions for working with matrices.
*/

// Matrix default constructor
struct Matrix Matrix(int rows, int columns) 
{
    return MatrixParams(rows, columns, NULL);
}

// Matrix constructor with parameters
struct Matrix MatrixParams(int rows, int columns, TYPE_ELEM *values) 
{
    // Memory allocation for matrix
    struct Matrix *matrix = (struct Matrix*)malloc(sizeof(struct Matrix));

    // Initialization fields of Matrix
    matrix->pThis = matrix;
    matrix->rows = rows;
    matrix->columns = columns;

    matrix->at = atMatrix;
    matrix->isSquare = isSquareMatrix;
    matrix->det = detMatrix;

    matrix->print = printMatrix;

    // Memory allocation for rows
    struct Row *pRows = (struct Row*)malloc(rows * sizeof(struct Row));

    // Initialization rows
    matrix->pRows = pRows;

    if (values == NULL) 
    {
        // Zero initialiation
        for (int i = 0; i < rows; ++i)
        {
            matrix->pRows[i] = Row(columns);
        }
    }
    else 
    {
        // Initialization by values
        for (int i = 0; i < rows; ++i) 
        {
            matrix->pRows[i] = RowParams(columns, (values + i * columns));
        }
    }

    return *matrix;   
}

// Matrix destructor
int DestructorMatrix(struct Matrix matrix) 
{
    // Call destructor for rows
    for (int i = 0; i < matrix.rows; ++i) 
    {
        DestructorRow(matrix.pRows[i]);
    }

    // Free memory of matrix
    free(matrix.pThis);

    return 0;
}

// Access element of Matrix
TYPE_ELEM atMatrix(int row, int column, struct Matrix matrix) 
{
    if ((matrix.rows <= row) || (matrix.columns <= column)) 
    {
        return 0;
    }

    TYPE_ELEM element = matrix.pRows[row].elements[column];

    return element;
}

// Check if matrix is ​​square
int isSquareMatrix(struct Matrix matrix) 
{
    if (matrix.rows = matrix.columns) 
    {
        return 1;
    }

    return 0;
}

// Computed determinant of matrix
TYPE_ELEM detMatrix(struct Matrix matrix) 
{
    // Check is square matrix
    // ...

    return 0.0;
}

// Print matrix
void printMatrix(struct Matrix matrix) 
{
    for (int i = 0; i < matrix.rows; ++i) 
    {
        for (int j = 0; j < matrix.columns; ++j) 
        {
            printf("%.3f\t", matrix.at(i, j, matrix));
        }

        printf("\n");
    }
}