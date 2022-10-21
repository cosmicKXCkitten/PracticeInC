/*
    Struct for row of matrix.

    [Attention!!!] This is a helper type - its use in user code
    is strictly prohibited.
*/
#ifndef ROW
#define ROW

// Row element type
#define TYPE_ELEM double

#include <stdlib.h>


typedef struct Row
{
    struct Row *pThis;

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

#endif
