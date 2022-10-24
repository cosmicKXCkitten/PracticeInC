#include "matrix.h"

/*
    Implementation functions for working with matrices.
*/

// Matrix default constructor
struct Matrix* Matrix(int rows, int columns) 
{
    return MatrixParams(rows, columns, NULL);
}

// Matrix constructor with parameters
struct Matrix* MatrixParams(int rows, int columns, TYPE_ELEM *values) 
{
    // Memory allocation for matrix
    struct Matrix *matrix = (struct Matrix*)malloc(sizeof(struct Matrix));

    // Initialization fields of Matrix
    matrix->pThis = matrix;
    matrix->rows = rows;
    matrix->columns = columns;

    matrix->at = atMatrix;
    matrix->set = setValueElementOfMatrix;
    matrix->isSquare = isSquareMatrix;
    matrix->det = detMatrix;

    matrix->print = printMatrix;
    matrix->setStatusCode = setStatusCodeOfMatrix;
    matrix->getStatusCode = getStatusCodeOfMatrix;

    // Memory allocation for rows
    struct Row *pRows = (struct Row*)malloc(rows * sizeof(struct Row));

    // Initialization rows
    matrix->pRows = pRows;

    if (values == NULL) 
    {
        // Zero initialization
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

    // Initialize status code of Matrix
    matrix->lastStatusCode = OK;

    return matrix;   
}

// Matrix copy constructor
struct Matrix* MatrixCopy(const struct Matrix* matrix) 
{
    // Create default matrix
    struct Matrix* cpMatrix = Matrix(matrix->rows, matrix->columns);

    // Copy values to cpMatrix
    for (int i = 0; i < matrix->rows; ++i) 
    {
        for (int j = 0; j < matrix->columns; ++j) 
        {
            cpMatrix->set(cpMatrix, i, j, matrix->at(matrix, i, j));
        }
    }

    return cpMatrix;
}

// Matrix by mask (zero initialization)
struct Matrix *MatrixByMask(int rows, int columns, int *mask) 
{
    // Memory allocation for matrix
    struct Matrix *matrix = (struct Matrix *)malloc(sizeof(struct Matrix));

    // Initialization fields of Matrix
    matrix->pThis = matrix;
    matrix->rows = rows;
    matrix->columns = columns;

    matrix->at = atMatrix;
    matrix->set = setValueElementOfMatrix;
    matrix->isSquare = isSquareMatrix;
    matrix->det = detMatrix;

    matrix->print = printMatrix;
    matrix->setStatusCode = setStatusCodeOfMatrix;
    matrix->getStatusCode = getStatusCodeOfMatrix;

    // Memory allocation for rows
    struct Row *pRows = (struct Row *)malloc(rows * sizeof(struct Row));

    // Initialization rows
    matrix->pRows = pRows;

    // Memory allocation and zero initialization rows
    for (int i = 0; i < rows; ++i) 
    {
        matrix->pRows[i] = Row(mask[i]);
    }

    matrix->setStatusCode(matrix, OK);

    return matrix;
}

// Matrix destructor
int DestructorMatrix(struct Matrix* matrix) 
{
    // Call destructor for rows
    for (int i = 0; i < matrix->rows; ++i) 
    {
        DestructorRow(matrix->pRows[i]);
    }

    // Free memory of matrix
    free(matrix->pThis);

    return 0;
}

// Access element of Matrix
TYPE_ELEM atMatrix(const struct Matrix* matrix, int row, int column)
{
    if ((matrix->rows <= row) || ((matrix->pRows[row]).size <= column)) 
    {
        matrix->setStatusCode(matrix, BAD_INDEX);
        return -1;
    }

    TYPE_ELEM element = matrix->pRows[row].elements[column];

    return element;
}

// Change value element of Matrix
void setValueElementOfMatrix(struct Matrix* matrix, int row, int column, TYPE_ELEM value) 
{
    if ((matrix->rows <= row) || (matrix->columns <= column))
    {
        matrix->setStatusCode(matrix, BAD_INDEX);
        return;
    }

    matrix->pRows[row].elements[column] = value;
}

// Check if matrix is ​​square
int isSquareMatrix(const struct Matrix* matrix) 
{
    if (matrix->rows == matrix->columns) 
    {
        return 1;
    }

    return 0;
}

// Computed determinant of matrix
TYPE_ELEM detMatrix(const struct Matrix* matrix) 
{
    /*
        The determinant will be calculated 
        using the decomposition on the first row.
    */

    // Check is square matrix
    if (matrix->isSquare(matrix)) 
    {
        // Matrix (or Minor) has one element
        if (matrix->rows == 1) 
        {
            return matrix->at(matrix, 0, 0);
        }

        TYPE_ELEM determinant = 0;

        // Matrix (or Minor) has four elements
        if (matrix->rows == 2) 
        {
            determinant = matrix->at(matrix, 0, 0) * matrix->at(matrix, 1, 1) - 
                          matrix->at(matrix, 0, 1) * matrix->at(matrix, 1, 0);
        }
        else if (matrix->rows >= 3) 
        {
            for (int k = 0; k < matrix->rows; ++k)
            {
                /*
                    A = (-1)^(i + j) * Minor, where i and j - indices

                    sign = (-1)^(i + j), where:
                        1. i = 1 (decomposition on the first row)
                        2. j = k

                    Eventually: sign = (-1)^(1 + k + 1), since
                    in mathematics indexing starts from one
                */
                TYPE_ELEM sign = pow(-1, k + 2);

                /*
                    factor = a[i][j] * sign (without multiplication by minor)
                */
                TYPE_ELEM factor = matrix->at(matrix, 0, k) * sign;

                /*
                    Create new matrix for compute Minor
                */
                // TYPE_ELEM *values;

                // struct Matrix minor = MatrixParams(matrix.rows - 1, matrix.columns - 1, values);

                /*
                    [member of decomposition] = factor * Minor
                    (where the minor is the determinant
                    of the matrix of the order below)
                */
                TYPE_ELEM member = factor * matrix->det(matrix);
                // !!! Attention - formule is not right

                determinant += member;
            }
        }
        
        return determinant;
    }

    return 0.0;
}

// Print matrix
void printMatrix(const struct Matrix* matrix) 
{
    for (int i = 0; i < matrix->rows; ++i) 
    {
        for (int j = 0; j < matrix->columns; ++j) 
        {
            TYPE_ELEM value = matrix->at(matrix, i, j); 
            
            if (value != -1) 
            {
                printf("%.3f\t", value);
            }
        }

        printf("\n");
    }
}

// Set status code of complete last operation
void setStatusCodeOfMatrix(struct Matrix* matrix, enum STATUS_CODE status_code) 
{
    matrix->lastStatusCode = status_code;
}

// Get status code of complete last operation
char* getStatusCodeOfMatrix(const struct Matrix* matrix) 
{
    switch (matrix->lastStatusCode)
    {
        case (OK):
        {
            return "OK";
        }
        case (BAD_INDEX):
        {
            return "BAD_INDEX";
        }
        case (BAD_INPUT_VALUE):
        {
            return "BAD_INPUT_VALUE";
        }
        case (MEMORY_ALLOCATION_ERROR):
        {
            return "MEMORY_ALLOCATION_ERROR";
        }
        case (INITIALIZATION_ERROR):
        {
            return "INITIALIZATION_ERROR";
        }
    }

    return "UNKNOWN ERROR";
}