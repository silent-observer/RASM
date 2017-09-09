#define rbtSet(RBTName) rbtSet_##RBTName
#define _getGrandparent(RBTName) _getGrandparent_##RBTName
#define _getUncle(RBTName) _getUncle_##RBTName
#define _rotateLeft(RBTName) _rotateLeft_##RBTName
#define _rotateRight(RBTName) _rotateRight_##RBTName
#define _rbtTestCase(NUM, RBTName) _rbtTestCase##NUM##_##RBTName

#define defineRBT_insert(RBTName, KeyType, ValueType)                           \
                                                                                \
static RBTNode(RBTName) *_getGrandparent(RBTName)(                              \
        const RBTNode(RBTName) *node) {                                         \
    if ((node != NULL) && (node->parent != NULL))                               \
        return node->parent->parent;                                            \
    else                                                                        \
        return NULL;                                                            \
}                                                                               \
                                                                                \
static RBTNode(RBTName) *_getUncle(RBTName)(                                    \
        const RBTNode(RBTName) *node) {                                         \
    RBTNode(RBTName) *g = _getGrandparent(RBTName)(node);                       \
    if (!g)                                                                     \
        return NULL;                                                            \
    if (node->parent == g->left)                                                \
        return g->right;                                                        \
    else                                                                        \
        return g->left;                                                         \
}                                                                               \
                                                                                \
static void _rotateLeft(RBTName)(                                               \
        RBTNode(RBTName) *node, RBTNode(RBTName) *g) {                          \
    RBTNode(RBTName) *p = node->parent;                                         \
    RBTNode(RBTName) *left = node->left;                                        \
    /*if (g)                                                                    \
        printfd("Left Rotate of %d with gran %d in\n", node->key, g->key);      \
    else                                                                        \
        printfd("Left Rotate of %d with gran (nil) in\n", node->key);           \
    debug(rbtDisplay(KeyType, ValueType)(node->parent, 0));*/                   \
    if (g) {                                                                    \
        if (p == g->left)                                                       \
            g->left = node;                                                     \
        else                                                                    \
            g->right = node;                                                    \
    }                                                                           \
    node->parent = g;                                                           \
    node->left = p; p->parent = node;                                           \
    p->right = left;                                                            \
    if (left)                                                                   \
        left->parent = p;                                                       \
}                                                                               \
                                                                                \
static void _rotateRight(RBTName)(                                              \
        RBTNode(RBTName) *node, RBTNode(RBTName) *g) {                          \
    RBTNode(RBTName) *p = node->parent;                                         \
    RBTNode(RBTName) *right = node->right;                                      \
    /*if (g)                                                                    \
        printf("Right Rotate of %d with gran %d in\n", node->key, g->key);      \
    else                                                                        \
        printf("Right Rotate of %d with gran (nil) in\n", node->key);           \
    rbtDisplay(KeyType, ValueType)(node->parent, 0);*/                          \
    if (g) {                                                                    \
        if (p == g->left)                                                       \
            g->left = node;                                                     \
        else                                                                    \
            g->right = node;                                                    \
    }                                                                           \
    node->parent = g;                                                           \
    node->right = p; p->parent = node;                                          \
    p->left = right;                                                            \
    if (right)                                                                  \
        right->parent = p;                                                      \
}                                                                               \
                                                                                \
static void _rbtTestCase(1, RBTName) (RBTNode(RBTName) *node);                  \
static void _rbtTestCase(2, RBTName) (RBTNode(RBTName) *node);                  \
static void _rbtTestCase(3, RBTName) (RBTNode(RBTName) *node);                  \
static void _rbtTestCase(4, RBTName) (RBTNode(RBTName) *node);                  \
static void _rbtTestCase(5, RBTName) (RBTNode(RBTName) *node);                  \
                                                                                \
static void _rbtTestCase(1, RBTName) (RBTNode(RBTName) *node) {                 \
    if (node->parent == NULL) {                                                 \
        node->color = BLACK_COLOR;                                              \
    } else {                                                                    \
        _rbtTestCase(2, RBTName)(node);                                         \
    }                                                                           \
}                                                                               \
static void _rbtTestCase(2, RBTName) (RBTNode(RBTName) *node) {                 \
    if (node->parent->color == BLACK_COLOR) {                                   \
        return;                                                                 \
    } else {                                                                    \
        _rbtTestCase(3, RBTName)(node);                                         \
    }                                                                           \
}                                                                               \
static void _rbtTestCase(3, RBTName) (RBTNode(RBTName) *node) {                 \
    RBTNode(RBTName) *u = _getUncle(RBTName)(node), *g;                         \
    if ((u != NULL) && (u->color == RED_COLOR)) {                               \
        node->parent->color = BLACK_COLOR;                                      \
        u->color = BLACK_COLOR;                                                 \
        g = u->parent;                                                          \
        g->color = RED_COLOR;                                                   \
        _rbtTestCase(1, RBTName)(g);                                            \
    } else {                                                                    \
        _rbtTestCase(4, RBTName)(node);                                         \
    }                                                                           \
}                                                                               \
static void _rbtTestCase(4, RBTName)(                                           \
        RBTNode(RBTName) *node) {                                               \
    RBTNode(RBTName) *g = _getGrandparent(RBTName)(node);                       \
    if ((node == node->parent->right) && (node->parent == g->left)) {           \
        _rotateLeft(RBTName)(node, g);                                          \
        node = node->left;                                                      \
    } else if ((node == node->parent->left) && (node->parent == g->right)) {    \
        _rotateRight(RBTName)(node, g);                                         \
        node = node->right;                                                     \
    }                                                                           \
    _rbtTestCase(5, RBTName)(node);                                             \
}                                                                               \
static void _rbtTestCase(5, RBTName) (RBTNode(RBTName) *node) {                 \
    RBTNode(RBTName) *g = _getGrandparent(RBTName)(node);                       \
    node->parent->color = BLACK_COLOR;                                          \
    g->color = RED_COLOR;                                                       \
    if (node == node->parent->left)                                             \
        _rotateRight(RBTName)(                                                  \
            node->parent, _getGrandparent(RBTName)(node->parent));              \
    else                                                                        \
        _rotateLeft(RBTName)(                                                   \
            node->parent, _getGrandparent(RBTName)(node->parent));              \
}                                                                               \
                                                                                \
static void rbtSet(RBTName)(                                                    \
        RBTName *rbt,                                                           \
        const KeyType key, const ValueType value) {                             \
    int found = 0;                                                              \
    RBTNode(RBTName) *currentNode = rbt->root;                                  \
    if (!currentNode) {                                                         \
        found = 1;                                                              \
    } else while (!found) {                                                     \
        int cmp = rbt->cmp(currentNode->key, key);                              \
        if (cmp > 0) { /* If target is less than currentNode */                 \
            if (currentNode->left)                                              \
                currentNode = currentNode->left;                                \
            else {                                                              \
                found = 2;                                                      \
            }                                                                   \
        } else if (cmp < 0) { /* If target is greater than currentNode */       \
            if (currentNode->right)                                             \
                currentNode = currentNode->right;                               \
            else {                                                              \
                found = 3;                                                      \
            }                                                                   \
        } else {                                                                \
            currentNode->value = value;                                         \
            return;                                                             \
        }                                                                       \
    }                                                                           \
    RBTNode(RBTName) *newNode = (RBTNode(RBTName) *)                            \
        malloc(sizeof(RBTNode(RBTName)));                                       \
    newNode->color = RED_COLOR;                                                 \
    newNode->value = value;                                                     \
    newNode->key = key;                                                         \
    newNode->left = NULL;                                                       \
    newNode->right = NULL;                                                      \
    newNode->parent = found == 1? NULL: currentNode;                            \
    if (found == 1)                                                             \
        rbt->root = newNode;                                                    \
    else if (found == 2)                                                        \
        currentNode->left = newNode;                                            \
    else if (found == 3)                                                        \
        currentNode->right = newNode;                                           \
                                                                                \
    _rbtTestCase(1, RBTName)(newNode);                                          \
    currentNode = rbt->root;                                                    \
    while (currentNode->parent)                                                 \
        currentNode = currentNode->parent;                                      \
    rbt->root = currentNode;                                                    \
}
