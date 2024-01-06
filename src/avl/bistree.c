#include "bistree.h"

void bistree_init(BisTree *tree, int (*compare) (const void *key1, const void *key2), void (*destroy) (void *data)) {
    bitree_init(tree, destroy);
    tree->compare = compare;
}

static void destroy_left(BisTree *tree, BiTreeNode *node) {
    BiTreeNode **position;

    if (bitree_size(tree) == 0)
        return;

    if (node == NULL)
        position = &bitree_root(tree);
    else
        position = &bitree_left(node);
    
    if (*position != NULL) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        if (tree->destroy != NULL)
            tree->destroy(((AvlNode *) bitree_data(*position))->data);
        
        free(bitree_data(*position));
        free(*position);
        position = NULL;

        tree->size--;
    }
}

static void destroy_right(BisTree *tree, BiTreeNode *node) {
    BiTreeNode **position;

    if (bitree_size(tree) == 0)
        return;

    if (node == NULL)
        position = &bitree_root(tree);
    else
        position = &bitree_right(node);
    
    if (*position != NULL) {
        bitree_rem_right(tree, *position);
        bitree_rem_left(tree, *position);

        if (tree->destroy != NULL)
            tree->destroy(((AvlNode *) bitree_data(*position))->data);
        
        free(bitree_data(*position));
        free(*position);
        position = NULL;

        tree->size--;
    }
}

void bistree_destroy(BisTree *tree) {
    destroy_left(tree, NULL);
    memset(tree, 0, sizeof(BisTree));
}

static void rotate_left(BiTreeNode **node) {
    BiTreeNode *left, *grandchild;

    left = bitree_left(*node);
    
    // rotacao EE
    if (((AvlNode *) bitree_data(left))->factor == AVL_LEFT_HEAVY) {
        bitree_left(*node) = bitree_right(left);
        bitree_right(left) = *node;

        ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;

        *node = left;
    } else { // rotacao ED
        grandchild = bitree_right(left);
        bitree_right(left) = bitree_left(grandchild);
        bitree_left(grandchild) = left;
        bitree_left(*node) = bitree_right(grandchild);
        bitree_right(grandchild) = *node;

        switch (((AvlNode *) bitree_data(grandchild))->factor) {
            case AVL_LEFT_HEAVY:
                ((AvlNode *) bitree_data(*node))->factor = AVL_RIGHT_HEAVY;
                ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;
                break;

            case AVL_BALANCED:
                ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
                ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;
                break;
            
            case AVL_RIGHT_HEAVY:
                ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
                ((AvlNode *) bitree_data(left))->factor = AVL_LEFT_HEAVY;
                break;
        }

        ((AvlNode *) bitree_data(grandchild))->factor = AVL_BALANCED;
        *node = grandchild;
    }
}

static void rotate_right(BiTreeNode **node) {
    BiTreeNode *right, *grandchild;

    right = bitree_right(*node);

    // rotacao DD
    if (((AvlNode *) bitree_data(right))->factor == AVL_RIGHT_HEAVY) {
        bitree_right(*node) = bitree_left(right);
        bitree_left(right) = *node;

        ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlNode *) bitree_data(right))->factor = AVL_BALANCED;

        *node = right;
    } else { // rotacao DE
        grandchild = bitree_left(right);
        bitree_left(right) = bitree_right(grandchild);
        bitree_right(grandchild) = right;
        bitree_right(*node) = bitree_left(grandchild);
        bitree_left(grandchild) = *node;
    }

    switch (((AvlNode *) bitree_data(grandchild))->factor) {
        case AVL_LEFT_HEAVY:
            ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *) bitree_data(right))->factor = AVL_RIGHT_HEAVY;
            break;

        case AVL_BALANCED:
            ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *) bitree_data(right))->factor = AVL_BALANCED;
            break;
        
        case AVL_RIGHT_HEAVY:
            ((AvlNode *) bitree_data(*node))->factor = AVL_LEFT_HEAVY;
            ((AvlNode *) bitree_data(right))->factor = AVL_BALANCED;
            break;
    }

    ((AvlNode *) bitree_data(grandchild))->factor = AVL_BALANCED;
    *node = grandchild;
}

static int new_nodo_avl(AvlNode *avl_data, const void *data) {
    if ((avl_data = (AvlNode *) malloc(sizeof(AvlNode))) == NULL)
            return -1;

    avl_data->factor = AVL_BALANCED;
    avl_data->hidden = 0;
    avl_data->data = (void *) data;

    return 0;
}

static int insert(BisTree *tree, BiTreeNode **node, const void *data, int *balanced) {
    AvlNode *avl_data;
    int cmpval, retval;

    if (bitree_is_eob(*node)) {
        if (new_nodo_avl(avl_data, data) != 0)
            return -1;

        return bitree_ins_left(tree, *node, (void *) avl_data);
    } else {
        cmpval = tree->compare(data, ((AvlNode *) bitree_data(*node))->data);

        if (cmpval < 0) {
            if (bitree_is_eob(bitree_left(*node))) {
                if (new_nodo_avl(avl_data, data) != 0)
                    return -1;

                if (bitree_ins_left(tree, *node, (void *) avl_data) != 0)
                    return -1;
                
                *balanced = 0;
            } else {
                if ((retval = insert(tree, &bitree_left(*node), data, balanced)) != 0)
                    return retval;
            }

            if (!(*balanced)) {
                switch (((AvlNode *) bitree_data(*node))->factor) {
                    case AVL_LEFT_HEAVY:
                        rotate_left(node);
                        *balanced = 1;
                        break;

                    case AVL_BALANCED:
                        ((AvlNode *) bitree_data(*node))->factor = AVL_LEFT_HEAVY;
                        break;
                    
                    case AVL_RIGHT_HEAVY:
                        ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
                        *balanced = 1;
                        break;
                }
            }
        } else if (cmpval > 0) {
            if (bitree_is_eob(bitree_right(*node))) {
                if (new_nodo_avl(avl_data, data) != 0)
                    return -1;

                if (bitree_ins_right(tree, *node, (void *) avl_data) != 0)
                    return -1;
                
                *balanced = 0;
            } else {
                if ((retval = insert(tree, &bitree_right(*node), data, balanced)) != 0)
                    return retval;
            }

            if (!(*balanced)) {
                switch (((AvlNode *) bitree_data(*node))->factor) {
                    case AVL_LEFT_HEAVY:
                        ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
                        *balanced = 1;
                        break;

                    case AVL_BALANCED:
                        ((AvlNode *) bitree_data(*node))->factor = AVL_RIGHT_HEAVY;
                        break;
                    
                    case AVL_RIGHT_HEAVY:
                        rotate_right(node);
                        *balanced = 1;
                        break;
                }
            }
        } else {
            if (!((AvlNode *) bitree_data(*node))->hidden)
                return -1;

            if (tree->destroy != NULL)
                tree->destroy(((AvlNode *) bitree_data(*node))->data);

            ((AvlNode *) bitree_data(*node))->data = (void *) data;
            ((AvlNode *) bitree_data(*node))->hidden = 0;

            *balanced = 1;
        }
    }

    return 0;
}

int bistree_insert(BisTree *tree, const void *data) {
    int balanced = 0;
    return insert(tree, &bitree_root(tree), data, &balanced);
}

static int hide(BisTree *tree, BiTreeNode *node, const void *data) {
    
    int cmpval, retval;

    if (bitree_is_eob(node))
        return -1;

    cmpval = tree->compare(data, ((AvlNode *) bitree_data(node))->data);

    if (cmpval < 0)
        retval = hide(tree, bitree_left(node), data);
    else if (cmpval > 0) 
        retval = hide(tree, bitree_right(node), data);
    else {
        ((AvlNode *) bitree_data(node))->hidden = 1;
        retval = 0;
    }

    return retval;

}

int bistree_remove(BisTree *tree, const void *data) {
    return hide(tree, bitree_root(tree), data);
}

static int lookup(BisTree *tree, BiTreeNode *node, void **data) {
    int cmpval, retval;

    if (bitree_is_eob(node))
        return -1;

    cmpval = tree->compare(data, ((AvlNode *) bitree_data(node))->data);

    if (cmpval < 0)
        retval = lookup(tree, bitree_left(node), data);
    else if (cmpval > 0) 
        retval = lookup(tree, bitree_right(node), data);
    else {
        if (((AvlNode *) bitree_data(node))->hidden)
            return -1;

        *data = ((AvlNode *) bitree_data(node))->data;
        retval = 0;
    }

    return retval;
}

int bistree_lookup(BisTree *tree, void **data) {
    return lookup(tree, bitree_root(tree), data);
}