#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "bitree.h"
#include "list.h"

int preorder(const BiTreeNode *node, List *list);

int inorder(const BiTreeNode *node, List *list);

int posorder(const BiTreeNode *node, List *list);

#endif