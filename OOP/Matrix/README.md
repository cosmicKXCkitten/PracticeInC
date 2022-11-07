# MATRIX class on C programming language

![Insert from the matrix - a conversation with the architect](assets/ConvWithArchitectEng.gif)

Basically, the expected behavior is implemented.

## Implementation of matrices in C...

### Here's what has been done:

- **DEFAULT MATRIX CONSTRUCTOR**

```
// rows
int m = 3;
// columns
int n = 4;

struct Matrix* matrix = Matrix(m, n);

DestructorMatrix(matrix);
```

Creates a matrix on the heap with m rows and n columns of elements, filled with zeros.

- **MATRIX CONSTRUCTOR WITH PARAMETER**

```
double data[3][3] = 
{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
};

struct Matrix* matrix = MatrixParams(3, 3, data);

DestructorMatrix(matrix);
```

Creates a matrix on the heap filled with the data that is passed in the parameter (in this case, data). The sizes of data[][] and those passed to the constructor parameters must match!

- **MATRIX COPY CONSTRUCTOR**

```
// rows
int m = 3;
// columns
int n = 4;

struct Matrix* matrix1 = Matrix(m, n);

struct Matrix* matrix2 = MatrixCopy(matrix1);

DestructorMatrix(matrix1);
DestructorMatrix(matrix2);
```

Creates a matrix on the heap that is a copy of the matrix passed as a parameter to the copy constructor.

- **MATRIX DESTRUCTOR**

```
// rows
int m = 3;
// columns
int n = 4;

struct Matrix* matrix = Matrix(m, n);

DestructorMatrix(matrix);
```

Since the matrix is ​​a complex object and the memory for it is allocated on the heap, it needs a special constructor. ***ATTENTION*** - be sure to use the destructor ***EVERY TIME*** after working with matrices.

- **METHODS FOR WORKING WITH MATRIXES**

    [1] **matrix.at()**

    ```
    // will return the matrix element in i row and j column
    matrix.at(&matrix, i, j);
    ```

    Matrix element access method. When going out of bounds, changes the state of the matrix to BAD_INDEX.

    [2] **matrix.set()**

    ```
    //sets the value of the matrix element at position (i, j) to value
    matrix.set(&matrix, i, j, value);
    ```

    Sets the value of the passed argument as the desired element of the matrix. When going out of bounds, changes the state of the matrix to BAD_INDEX.

