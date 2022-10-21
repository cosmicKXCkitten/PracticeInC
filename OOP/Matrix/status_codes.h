#ifndef STATUS_CODES
#define STATUS_CODES

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
};

#endif