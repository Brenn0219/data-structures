#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>
#include <memory.h>

/// @brief Estrutura de No para Arvore
typedef struct BiTreeNode {
    void *data;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
} BiTreeNode;

/// @brief Estrutura de Arvore
typedef struct BiTree {
    int size;

    int (*compare) (const void *key1, const void *key2);
    void (*destroy) (void *data);

    BiTreeNode *root;
} BiTree;

/// @brief Inicializa uma arvore binaria 
/// @param tree arvore binaria 
/// @param destroy ponteiro para funcao, remover/liberar os dados que foram alocados dinamicamente. Para uma tabela hasing que contenha dados que nao devem ser liberados, destroy deve ser definido como NULL
/// @complexity O(1)
void bitree_init(BiTree *tree, void (*destroy) (void *data));

/// @brief Destroi uma arvore binaria 
/// @param tree uma arvore binaria
/// @complexity O(n)
void bitree_destroy(BiTree *tree);

/// @brief Insere um nodo como o filho da esquerda do nodo na arvore binaria
/// @param tree arvore binaria
/// @param node nodo a ser inserido
/// @param data ponteiro para o dado a ser inserido
/// @return 0 se a insercao do nodo for bem sucedida, do contrario -1
/// @complexity O(1)
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data);

/// @brief Insere um nodo como o filho da direita do nodo na arvore binaria
/// @param tree arvore binaria
/// @param node nodo a ser inserido
/// @param data ponteiro para o dado a ser inserido
/// @return 0 se a insercao do nodo for bem sucedida, do contrario -1
/// @complexity O(1)
int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data);

/// @brief Remove a subarvore enraizada como o filho esquerdo do node da arvore binaria
/// @param tree arvore binaria
/// @param node nodo a ser removido
/// @return 0 se a remocao do nodo for bem sucedida, do contrario -1
/// @complexity O(n)
int bitree_rem_left(BiTree *tree, BiTreeNode *node);

/// @brief Remove a subarvore enraizada como o filho direito do node da arvore binaria
/// @param tree arvore binaria
/// @param node nodo a ser removido
/// @return 0 se a remocao do nodo for bem sucedida, do contrario -1
/// @complexity O(n)
int bitree_rem_right(BiTree *tree, BiTreeNode *node);

/// @brief Junta duas arvores binarias especificadas por left e right em uma unica arvore binaria
/// @param merge juncao das duas arvores
/// @param left subarvore da esquerda
/// @param right subarvore da direita
/// @param data raiz da juncao da duas arvores
/// @return 0 se a juncao das arvores for bem sucedida, do contrario -1
/// @complexity O(n)
int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data);

/// @brief Macro que avalia o numero de nodos na arvore binaria 
#define bitree_size(tree) ((tree)->size)

/// @brief Macro que avalia o nodo na raiz da arvore binaria
#define bitree_root(tree) ((tree)->root)

/// @brief Macro que determina se o nodo especificado por node marca o fim de uma ramificacao 
#define bitree_is_eob(node) ((node) == NULL)

/// @brief Macro que determina se o nodo especificado por node e o node de uma folha
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)

/// @brief Macro que avalia os dados armazenados no nodo de uma arvore binaria
#define bitree_data(node) ((node)->data)

/// @brief Macro que avalia o nodo de uma arvore binaria, que e o filho esquerdo do nodo definido como node
#define bitree_left(node) ((node)->left)

/// @brief Macro que avalia o nodo de uma arvore binaria, que e o filho direito do nodo definido como node
#define bitree_right(node) ((node)->right)

#endif