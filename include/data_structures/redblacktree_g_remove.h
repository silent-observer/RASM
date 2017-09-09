#define rbtRemove(RBTName) rbtRemove_##RBTName
#define rbtRemoveNode(RBTName) rbtRemove_##RBTName
#define _rbtRemoveDoubleBlack(RBTName) _rbtRemoveDoubleBlack_##RBTName
#define _rbtRemoveNode(RBTName) _rbtRemoveNode_##RBTName

#define defineRBT_remove(RBTName, KeyType, ValueType)                           \
                                                                                \
static void _rbtRemoveDoubleBlack(RBTName) (RBTNode(RBTName) *node,             \
        RBTName rbt) {                                                          \
    /*printfd("Removing double black at:\n");                                   \
    debug(rbtDisplay(KeyType, ValueType)(node, 0));*/                           \
    int toDelete = 1;                                                           \
    while (node->parent) {                                                      \
        RBTNode(RBTName) *sibling;                                              \
        int siblingSide;                                                        \
        if (node == node->parent->left) {                                       \
            sibling = node->parent->right;                                      \
            siblingSide = 0;                                                    \
        } else {                                                                \
            sibling = node->parent->left;                                       \
            siblingSide = 1;                                                    \
        }                                                                       \
        /*printfd("Sibling(%d): \n", siblingSide);                              \
        debug(rbtDisplay(KeyType, ValueType)(sibling, 0));*/                    \
        if (sibling == NULL || sibling->color == BLACK_COLOR) {                 \
            int slRed = (sibling->left != NULL &&                               \
                sibling->left->color == RED_COLOR);                             \
            int srRed = (sibling->right != NULL &&                              \
                sibling->right->color == RED_COLOR);                            \
            /*printfd("SL/SR: %d/%d\n", slRed, srRed);*/                        \
            if (slRed || srRed) {                                               \
                if (siblingSide && !slRed && srRed) {                          \
                    /*printfd("Cl#1\n");*/                                           \
                    _rotateLeft(RBTName)(                                       \
                        sibling->right, node->parent);                          \
                    sibling->color = RED_COLOR;                                 \
                    sibling = sibling->parent;                                  \
                    sibling->color = BLACK_COLOR;                               \
                } else if (!siblingSide && slRed && !srRed) {                    \
                    /*printfd("Cl#2\n");*/                                          \
                    _rotateRight(RBTName)(                                      \
                        sibling->left, node->parent);                          \
                    sibling->color = RED_COLOR;                                 \
                    sibling = sibling->parent;                                  \
                    sibling->color = BLACK_COLOR;                               \
                }                                                               \
                if (siblingSide) {                                             \
                    /*printfd("Cl#3\n");*/                                           \
                    _rotateRight(RBTName)(                            \
                        sibling, node->parent->parent);                         \
                } else {                                                        \
                    /*printfd("Cl#4\n");*/                                           \
                    _rotateLeft(RBTName)(                           \
                        sibling, node->parent->parent);                         \
                }                                                               \
                sibling->left->color = BLACK_COLOR;                             \
                sibling->right->color = BLACK_COLOR;                            \
                sibling->color = RED_COLOR;                                     \
                break;                                                          \
            } else {                                                            \
                /*printfd("Cl#5\n");*/                                              \
                sibling->color = RED_COLOR;                                     \
                if (node->parent->color == RED_COLOR) {                         \
                    node->parent->color = BLACK_COLOR;                          \
                    break;                                                      \
                } else {                                                        \
                    node = node->parent;                                        \
                    if (toDelete) {                                             \
                        if (siblingSide) {                                      \
                            rbt.dstr(node->right);                              \
                            node->right = NULL;                                 \
                        } else {                                                \
                            rbt.dstr(node->left);                               \
                            node->left = NULL;                                  \
                        }                                                       \
                        toDelete = 0;                                           \
                    }                                                           \
                    /*printfd("New double black node: \n");                       \
                    debug(rbtDisplay(KeyType, ValueType)(node, 0));*/           \
                    continue;                                                   \
                }                                                               \
            }                                                                   \
        } else {                                                                \
            if (siblingSide)                                                    \
                _rotateRight(RBTName)(                               \
                    sibling, node->parent->parent);                             \
            else                                                                \
                _rotateLeft(RBTName)(                                \
                    sibling, node->parent->parent);                             \
            node->parent->color = RED_COLOR;                                    \
            node->parent->parent->color = BLACK_COLOR;                          \
            /*printfd("Cl#6\n");                                                  \
            debug(rbtDisplay(KeyType, ValueType)(node->parent->parent, 0));*/     \
            continue;                                                           \
                                                                                \
        }                                                                       \
    }                                                                           \
    if (!node->parent)                                                          \
        node->color = BLACK_COLOR;                                              \
    if (toDelete) {                                                             \
        if (node == node->parent->right)                                        \
            node->parent->right = NULL;                                         \
        else                                                                    \
            node->parent->left = NULL;                                          \
        rbt.dstr(node);                                                         \
    }                                                                           \
}                                                                               \
                                                                                \
static void _rbtRemoveNode(RBTName) (RBTNode(RBTName) *node, RBTName rbt) {     \
    RBTNode(RBTName) *child = node->left? node->left : node->right;             \
    if (node->color == RED_COLOR ||                                             \
            (child != NULL && child->color == RED_COLOR)) {                     \
        if (node == node->parent->left)                                         \
            node->parent->left = child;                                         \
        else                                                                    \
            node->parent->right = child;                                        \
        if (child) {                                                            \
            child->parent = node->parent;                                       \
            child->color = BLACK_COLOR;                                         \
        }                                                                       \
        rbt.dstr(node);                                                         \
        return;                                                                 \
    }                                                                           \
    _rbtRemoveDoubleBlack(RBTName) (node, rbt);                                 \
}                                                                               \
                                                                                \
static int rbtRemove(RBTName) (RBTName *rbt, const KeyType key) {               \
    RBTNode(RBTName) *node = rbtGet(RBTName)(*rbt, key);                        \
    if (node == NULL) return 0;                                                 \
    /*printf("Removing node:\n");                                               \
    rbtDisplay(KeyType, ValueType)(node, 0);*/                                  \
    RBTNode(RBTName) *currentNode = node;                                       \
    if (node->left != NULL && node->right != NULL) {                            \
        currentNode = currentNode->right;                                       \
        while (currentNode->left)                                               \
            currentNode = currentNode->left;                                    \
        node->value = currentNode->value;                                       \
        node->key = currentNode->key;                                           \
    }                                                                           \
    /*printf("After copying:\n");                                               \
    rbtDisplay(KeyType, ValueType)(node, 0);*/                                  \
    _rbtRemoveNode(RBTName) (currentNode, *rbt);                                \
    currentNode = rbt->root;                                                    \
    while (currentNode->parent)                                                 \
        currentNode = currentNode->parent;                                      \
    rbt->root = currentNode;                                                    \
    return 1;                                                                   \
}
