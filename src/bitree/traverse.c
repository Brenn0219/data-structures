#include "traverse.h"

int preorder(const BiTreeNode *node, List *list) {
    if (!bitree_is_eob(node)) {
        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;

        if (!bitree_is_eob(bitree_left(node))) {
            if (preorder(bitree_left(node), list) != 0)
                return -1;
        }

        if (!bitree_is_eob(bitree_right(node))) {
            if (preorder(bitree_right(node), list) != 0)
                return -1;
        }
    }

    return 0;
}

int inorder(const BiTreeNode *node, List *list) {
    if (!bitree_is_eob(node)) {
        if (!bitree_is_eob(bitree_left(node))) {
            if (preorder(bitree_left(node), list) != 0)
                return -1;
        }

        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;

        if (!bitree_is_eob(bitree_right(node))) {
            if (preorder(bitree_right(node), list) != 0)
                return -1;
        }
    }

    return 0;
}

int posorder(const BiTreeNode *node, List *list) {
    if (!bitree_is_eob(node)) {
        if (!bitree_is_eob(bitree_left(node))) {
            if (preorder(bitree_left(node), list) != 0)
                return -1;
        }

        if (!bitree_is_eob(bitree_right(node))) {
            if (preorder(bitree_right(node), list) != 0)
                return -1;
        }

        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;
    }

    return 0;
}