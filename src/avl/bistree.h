#ifndef BISTREE_H
#define BISTREE_H

#include "bitree.h"

#define AVL_LEFT_HEAVY 1
#define AVL_BALANCED 0
#define AVL_RIGHT_HEAVY -1

/// @brief 
typedef struct AvlNode {
    void *data;
    int hidden;
    int factor;
} AvlNode;

/// @brief 
typedef BiTree BisTree;

/// @brief Inicializa a arvore de busca binaria 
/// @param tree arvore de busca binaria
/// @param compare ponteiro de funcao que compara os nodos. Esta funcao deve retornar 1 se key1 > key2, 0 key1 == ke2 e -1 se key1 < key2
/// @param destroy ponteiro para funcao, remover/liberar os dados que foram alocados dinamicamente. Para uma tabela hasing que contenha dados que nao devem ser liberados, destroy deve ser definido como NULL
/// @complexity O(1)
void bistree_init(BisTree *tree, int (*compare) (const void *key1, const void *key2), void (*destroy) (void *data));

/// @brief Destroi a arvore de busca binaria
/// @param tree arvore de busca binaria
/// @complexity O(n)
void bistree_destroy(BisTree *tree);

/// @brief Insere um nodo em uma arvore de busca binaria  
/// @param tree arvore de busca binaria
/// @param data ponteiro para o dado a ser inserido
/// @return 0 se a insercao do nodo for bem sucedida, 1 se o nodo ja estiver na arvore, do contrario -1
/// @complexity O(lg n)
int bistree_insert(BisTree *tree, const void *data);

/// @brief Remove um nodo em uma arvore de busca binaria  
/// @param tree arvore de busca binaria
/// @param data ponteiro para o dado a ser removido
/// @return 0 se a remocao do nodo for bem sucedida, do contrario -1
/// @complexity O(lg n)
int bistree_remove(BisTree *tree, const void *data);

/// @brief Determina se o nodo combina com data na arvore de busca binaria
/// @param tree na arvore de busca binaria
/// @param data ponteiro para o endereco do dado a ser pesquisado
/// @return 0 se os dados forem encontrados na arvore de busca binaria, do contrario -1
/// @complexity O(lg n)
int bistree_lookup(BisTree *tree, void **data);

/// @brief Macro que avalia o numero de nodos na arvore de busca binaria 
#define bistree_size(tree) ((tree)->size);

#endif