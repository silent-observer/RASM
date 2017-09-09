#ifndef _LINKED
#define _LINKED

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

#define LList(LListName) LList_ ## LListName
#define _lList(LListName) _lList_ ## LListName
#define LListNode(LListName) LListNode_ ## LListName
#define _lListNode(LListName) _lListNode_ ## LListName
#define newLList(LListName) newLList_ ## LListName
#define deleteLList(LListName) deleteLList_ ## LListName
#define llAppend(LListName) llAppend_ ## LListName
#define llInsertBefore(LListName) llInsertBefore_ ## LListName
#define llRemove(LListName) llRemove_ ## LListName
#define llAppendL(LListName) llAppendL_ ## LListName
#define llInsertBeforeL(LListName) llInsertBeforeL_ ## LListName
#define llRemoveL(LListName) llRemoveL_ ## LListName
#define llDuplicate(LListName) llDuplicate_ ## LListName

#define defineLList(LListName, type)                                            \
typedef struct _lListNode(LListName) {                                          \
    type data;                                                                  \
    struct _lListNode(LListName) *next, *prev;                                  \
} LListNode(LListName);                                                         \
                                                                                \
typedef struct _lList(LListName) {                                              \
    LListNode(LListName) *start, *end;                                          \
    void (*dstr)(LListNode(LListName)*);                                        \
} LList(LListName);                                                             \
                                                                                \
typedef LList(LListName) LListName;                                             \
typedef LListNode(LListName) LListName ## Node;                                 \
                                                                                \
static LListName newLList(LListName)(void (*dstr)(LListNode(LListName)*)) {     \
    LListName result = {NULL, NULL, dstr};                                      \
    return result;                                                              \
}                                                                               \
                                                                                \
static void deleteLList(LListName)(LListName list) {                            \
    if (list.start) {                                                           \
        for (LListNode(LListName) *n = list.start->next;                    \
                n != NULL; n = n->next) {                                   \
            list.dstr(n->prev);                                             \
        }                                                                   \
        list.dstr(list.end);                                                \
    }                                                                           \
}                                                                               \
                                                                                \
static void llAppend(LListName)(LListName *list, type data) {                   \
    LListNode(LListName)* newNode = (LListNode(LListName)*)                     \
                                malloc(sizeof(LListNode(LListName)));           \
    newNode->data = data;                                                       \
    newNode->next = NULL;                                                       \
    if (!list->start) {                                                         \
        newNode->prev = NULL;                                                   \
        list->start = newNode;                                                  \
    } else {                                                                    \
        newNode->prev = list->end;                                              \
        list->end->next = newNode;                                              \
    }                                                                           \
    list->end = newNode;                                                        \
}                                                                               \
                                                                                \
static void llInsertBefore(LListName)(                                          \
        LListName *list, LListNode(LListName) *element, type data) {            \
    LListNode(LListName)* newNode = (LListNode(LListName)*)                     \
                                malloc(sizeof(LListNode(LListName)));           \
    newNode->data = data;                                                       \
    newNode->next = element;                                                    \
    newNode->prev = element->prev;                                              \
    if (element->prev)                                                          \
        element->prev->next = newNode;                                          \
    element->prev = newNode;                                                    \
    if (!newNode->prev)                                                         \
        list->start = newNode;                                                  \
}                                                                               \
                                                                                \
static void llRemove(LListName)(LListName *list,                                \
        LListNode(LListName) *element) {                                        \
    if (element->next)                                                          \
        element->next->prev = element->prev;                                    \
    else                                                                        \
        list->end = element->prev;                                              \
    if (element->prev)                                                          \
        element->prev->next = element->next;                                    \
    else                                                                        \
        list->start = element->next;                                            \
    list->dstr(element);                                                        \
}                                                                               \
                                                                                \
static void llAppendL(LListName)(LListName *list, LListName data) {             \
    if (!list->start) {                                                         \
        data.start->prev = NULL;                                                \
        list->start = data.start;                                               \
    } else {                                                                    \
        data.start->prev = list->end;                                           \
        list->end->next = data.start;                                           \
    }                                                                           \
    list->end = data.end;                                                       \
}                                                                               \
                                                                                \
static void llInsertBeforeL(LListName)(                                         \
        LListName *list, LListNode(LListName) *element, LListName data) {       \
    if (!element->prev)                                                         \
        list->start = data.start;                                               \
    else {                                                                      \
        data.start->prev = element->prev;                                       \
        element->prev->next = data.start;                                       \
    }                                                                           \
    element->prev = data.end;                                                   \
    data.end->next = element;                                                   \
}                                                                               \
                                                                                \
static void llRemoveL(LListName)(LListName *list, LListName elements) {         \
    if (elements.end->next)                                                     \
        elements.end->next->prev = elements.start->prev;                        \
    else                                                                        \
        list->end = elements.start->prev;                                       \
    if (elements.start->prev)                                                   \
        elements.start->prev->next = elements.end->next;                        \
    else                                                                        \
        list->start = elements.end->next;                                       \
    elements.end->next = NULL;                                                  \
    elements.start->prev = NULL;                                                \
    elements.dstr = list->dstr;                                                 \
    deleteLList(LListName)(elements);                                           \
}                                                                               \
                                                                                \
static LListName llDuplicate(LListName)(const LListName list) {                 \
    LListName newList = newLList(LListName)(list.dstr);                         \
    for (LListNode(LListName) *n = list.start; n != NULL; n = n->next)          \
        llAppend(LListName)(&newList, n->data);                                 \
    return newList;                                                             \
}

#endif
