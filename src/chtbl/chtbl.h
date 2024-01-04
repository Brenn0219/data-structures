#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>
#include <memory.h>
#include "list.h"

/// @brief Estrutura de dados da Tabela Hashing Encadeada
typedef struct CHTbl {
    int buckets;

    int (*h) (const void *key);
    int (*match) (const void *key1, const void *key2);
    void (*destroy) (void *data);

    int size;
    List *table;
} CHTbl;

/// @brief Inicializa uma tabela hashing encadeada 
/// @param htbl tabela hashing encadeada
/// @param buckets numero de particoes alocadas na tabela hashing
/// @param h ponteiro para uma funcao para chaves hashing
/// @param match ponteiro para funcao para verificar se duas chaves coincidem
/// @param destroy ponteiro para funcao, remover/liberar os dados que foram alocados dinamicamente. Para uma tabela hasing que contenha dados que nao devem ser liberados, destroy deve ser definido como NULL
/// @return 0 se a inicializacao da tabela foi bem sucedida, do contrario -1
/// @complexity O(n) 
int chtbl_int(CHTbl *htbl, int buckets, int (*h) (const void *key), int (*match) (const void *key1, const void *key2), void (*destroy) (void *data));

/// @brief Destroi uma tabela hashing encadeada
/// @param htbl tabela hashing encadeada
void chtbl_destroy(CHTbl *htbl);

/// @brief Insere um elemento na tabela hashing encadeada
/// @param htbl tabela hashing encadeada
/// @param data ponteiro para o dado a ser inserido
/// @return 0 se a insercao de elemento e bem sucedida, 1 se o elemento ja estiver na tabela hashing, do contrario -1
/// @complexity O(1) 
int chtbl_insert(CHTbl *htbl, const void *data);

/// @brief Remove o elemento que coincide com data na tabela hashing encadeada
/// @param htbl tabela hashing encadeada
/// @param data ponteiro para o dado a ser removido
/// @return 0 se a remocao for bem sucedida, do contrario -1
/// @complexity O(1)
int chtbl_remove(CHTbl *htbl, void **data);

/// @brief Determinar se a tabela ja tem o elemento data
/// @param htbl tabela hashing encadeada
/// @param data ponteiro para o dado a ser pesquisado
/// @return 0 se o elemento for encontrado na tabela hashing, do contrario -1
/// @complexity O(1)
int chtbl_lookup(const CHTbl *htbl, void **data);

/// @brief Macro que avalia o numero de elementos na tabela hashing encadeada
#define chtbl_size(htbl) ((htbl)->size)

#endif