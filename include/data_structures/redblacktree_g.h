#ifndef _RBT
#define _RBT

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#define RED_COLOR 0
#define BLACK_COLOR 1

#define _rbtNode(RBTName) _rbtNode_##RBTName
#define RBTNode(RBTName) RBTNode_##RBTName
#define RedBlackTree(RBTName) RedBlackTree_##RBTName
#define newRBT(RBTName) newRBT_##RBTName
#define deleteRBT(RBTName) deleteRBT_##RBTName
#define foreachRBTNode(RBTName) foreachRBTNode_##RBTName
#define foreachRBT(RBTName) foreachRBT_##RBTName
#define rbtGet(RBTName) rbtGet_##RBTName
#define rbtDisplay(RBTName) rbtDisplay_##RBTName

#include "redblacktree_g_insert.h"
#include "redblacktree_g_remove.h"
#define defineRBT(RBTName, KeyType, ValueType)                                  \
typedef struct _rbtNode(RBTName) {                                              \
    KeyType key;                                                                \
    ValueType value;                                                            \
    char color;                                                                 \
    struct _rbtNode(RBTName) *left;                                             \
    struct _rbtNode(RBTName) *right;                                            \
    struct _rbtNode(RBTName) *parent;                                           \
} RBTNode(RBTName);                                                             \
                                                                                \
typedef struct {                                                                \
    RBTNode(RBTName)* root;                                                     \
    int (*cmp) (KeyType, KeyType);                                              \
    void (*dstr) (RBTNode(RBTName)*);                                            \
} RedBlackTree(RBTName);                                                        \
                                                                                \
typedef RedBlackTree(RBTName) RBTName;                                          \
typedef RBTNode(RBTName) *RBTName ## Entry;                                     \
                                                                                \
static RBTName newRBT(RBTName)(                                                 \
        int (*cmp) (KeyType, KeyType), void (*dstr) (RBTNode(RBTName)*)) {      \
    RBTName rbt;                                                                \
    rbt.root = NULL;                                                            \
    rbt.cmp = cmp;                                                              \
    rbt.dstr = dstr;                                                            \
    return rbt;                                                                 \
}                                                                               \
                                                                                \
/*static void rbtDisplay(KeyType, ValueType)(                                     \
        RBTNode(KeyType, ValueType) *rbt, int _level) {                         \
    for (int i = 0; i < _level; i++)                                            \
        printf(" ");                                                            \
    if (rbt->color == RED_COLOR)                                                \
        printf("{%d:%d}\n", rbt->key, rbt->value);                              \
    else                                                                        \
        printf("[%d:%d]\n", rbt->key, rbt->value);                              \
                                                                                \
    if (rbt->left)                                                              \
        rbtDisplay(KeyType, ValueType)(rbt->left, _level+1);                    \
    else {                                                                      \
        for (int i = 0; i < _level+1; i++)                                      \
            printf(" ");                                                        \
        printf("[nil]\n");                                                      \
    }                                                                           \
    if (rbt->right)                                                             \
        rbtDisplay(KeyType, ValueType)(rbt->right, _level+1);                   \
    else {                                                                      \
        for (int i = 0; i < _level+1; i++)                                      \
            printf(" ");                                                        \
        printf("[nil]\n");                                                      \
    }                                                                           \
}*/                                                                             \
static RBTNode(RBTName) *rbtGet(RBTName)(                                       \
        const RBTName rbt, const KeyType key) {                                 \
    RBTNode(RBTName) *currentNode = rbt.root;                                   \
    while (currentNode) {                                                       \
        int cmp = rbt.cmp(currentNode->key, key);                               \
        if (cmp == 0) /* If found target node */                                \
            return currentNode;                                                 \
        else if (cmp > 0) /* If target is less than currentNode */              \
            currentNode = currentNode->left;                                    \
        else /* If target is greater than currentNode */                        \
            currentNode = currentNode->right;                                   \
    }                                                                           \
    return NULL;                                                                \
}                                                                               \
static void foreachRBTNode(RBTName)(RBTNode(RBTName) *n,                        \
        void (*func)(RBTNode(RBTName)*)) {                                       \
    if (n->left)                                                                \
        foreachRBTNode(RBTName)(n->left, func);                                 \
    if (n->right)                                                               \
        foreachRBTNode(RBTName)(n->right, func);                                \
    func(n);                                                                    \
}                                                                               \
static void foreachRBT(RBTName)(RBTName rbt,                                    \
        void (*func)(RBTNode(RBTName)*)) {                                      \
    if (rbt.root)                                                               \
        foreachRBTNode(RBTName)(rbt.root, func);                                \
}                                                                               \
static void deleteRBT(RBTName)(RBTName rbt) {                                   \
    foreachRBT(RBTName)(rbt, rbt.dstr);                                         \
}                                                                               \
                                                                                \
defineRBT_insert(RBTName, KeyType, ValueType)                                   \
defineRBT_remove(RBTName, KeyType, ValueType)                                   \

#endif
