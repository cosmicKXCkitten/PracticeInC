#include "row.h"

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
    struct Row *row = (struct Row *)malloc(sizeof(struct Row));

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