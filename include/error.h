#ifndef _ERROR
#define _ERROR

#include <stdio.h>

#define test(A, ...) do {if (A) { \
    fprintf(stderr, __VA_ARGS__); \
    exit(EXIT_FAILURE); \
}} while(0)

#define testP(A, ...) do {if (A) { \
    fprintf(stderr, __VA_ARGS__, __FILE__, __LINE__); \
    exit(EXIT_FAILURE); \
}} while(0)

#ifdef DEBUG
    #define debug(X) do {X;} while(0)
#else
    #define debug(X) do {} while(0)
#endif

#define printfd(...) debug(fprintf(stderr, __VA_ARGS__))
#endif
