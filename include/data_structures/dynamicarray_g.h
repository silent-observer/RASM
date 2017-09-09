#ifndef _DYNAMIC
#define _DYNAMIC

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

#define DArray(DArrayName) DArray_ ## DArrayName
#define newDArray(DArrayName) newDArray_ ## DArrayName
#define daAppendN(DArrayName) daAppendN_ ## DArrayName
#define daAppend(DArrayName) daAppend_ ## DArrayName
#define daAppendArr(DArrayName) daAppendArr_ ## DArrayName

#define defineDArray(DArrayName, type)                                          \
typedef struct {                                                                \
    type *data;                                                                 \
    uint16_t capasity;                                                          \
    uint16_t size;                                                              \
} DArray(DArrayName);                                                           \
                                                                                \
typedef DArray(DArrayName) DArrayName;                                          \
                                                                                \
static DArrayName newDArray(DArrayName)(size_t baseCapasity) {                  \
    type *data = (type*) calloc(baseCapasity, sizeof (type));                   \
    test(!data, "Cannot allocate memory for dynamic array");                    \
                                                                                \
    DArrayName res;                                                             \
    res.data = data;                                                            \
    res.capasity = baseCapasity;                                                \
    res.size = 0;                                                               \
    return res;                                                                 \
}                                                                               \
                                                                                \
static void daAppendN(DArrayName) (DArrayName *array,                           \
        const type *data, size_t count) {                                       \
    if (array->size + count > array->capasity) {                                \
        type *newData = (type *) calloc( (count+array->capasity)*2,             \
            sizeof(type));                                                      \
        test(!newData, "Cannot allocate memory for dynamic array");             \
        memcpy(newData, array->data, array->capasity);                          \
        free(array->data);                                                      \
        array->data = newData;                                                  \
        array->capasity = (count+array->capasity)*2;                            \
    }                                                                           \
    memcpy((type *)array->data + array->size, data,                             \
        sizeof(type)*count);                                                    \
    array->size += count;                                                       \
}                                                                               \
                                                                                \
static void daAppend(DArrayName)(DArrayName *array, const type *data) {         \
    daAppendN(DArrayName)(array, data, 1);                                      \
}                                                                               \
                                                                                \
static void daAppendArr(DArrayName)(DArrayName *array,                          \
        DArrayName *data) {                                                     \
    daAppendN(DArrayName)(array, data->data, data->size);                       \
}

#endif
