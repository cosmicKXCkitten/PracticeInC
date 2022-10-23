/*
    Type declarations used in the library
*/
#ifndef __TYPES_H__
#define __TYPES_H__

#if !defined(__MATRIX_H__) && !defined(__COMPILATION__)
#error "Only <matrix.h> can be included directly."
#endif

#define TYPE_ELEM double
struct Matrix;
enum STATUS_CODE;

typedef TYPE_ELEM (*FuncAt) (const struct Matrix, int, int);
typedef void (*FuncSet) (struct Matrix, int, int, TYPE_ELEM);
typedef int (*FuncIsSquare) (const struct Matrix);
typedef TYPE_ELEM (*FuncDetMatrix) (const struct Matrix);
typedef void (*FuncPrintMatrix) (const struct Matrix);
typedef void (*FuncSetStatusCode) (struct Matrix, enum STATUS_CODE);
typedef char* (*FuncGetStatusCode) (const struct Matrix);

#endif /* __TYPES_H__ */