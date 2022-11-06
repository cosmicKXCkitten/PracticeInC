# MATRIX class on C programming language

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
```

Creates a matrix on the heap that is a copy of the matrix passed as a parameter to the copy constructor.