#ifndef STATUS_CODES
#define STATUS_CODES

#if !defined(__MATRIX_H__) && !defined(__COMPILATION__)
#error "Only <matrix.h> can be included directly."
#endif

/*
    Status codes for analyzing the operation 
    of programs (their output values)
*/
typedef enum STATUS_CODE
{
    BAD_INDEX = -1,
    OK = 0,
    ERROR = 1,
    BAD_INPUT_VALUE = 2,
    MEMORY_ALLOCATION_ERROR = 3,
};

#endif