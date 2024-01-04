#ifndef OHTBL_H
#define OHTBL_H

#include <stdlib.h>
#include <memory.h>
#include "list.h"

/// @brief Estrutura de dados da Tabela Hashing de Enderecamento Livre
typedef struct OHTbl {
    int positions;
    void *vacated;

    int (*ht1) (const void *key);
    int (*ht2) (const void *key);
    int (*match) (const void *key1, const void *key2);
    void (*destroy) (void *data);

    int size;
    List **table;
} OHTbl;

/// @brief Inicializa uma tabela hashing de enderecamento livre 
/// @param htbl tabela hashing de enderecamento livre
/// @param positions numero de posicoes alocadas na tabela hashing
/// @param ht1 ponteiro para uma funcao para chave hash auxiliar
/// @param ht2 ponteiro para uma funcao para chave hash auxiliar
/// @param match ponteiro para funcao para verificar se duas chaves coincidem
/// @param destroy ponteiro para funcao, remover/liberar os dados que foram alocados dinamicamente. Para uma tabela hasing que contenha dados que nao devem ser liberados, destroy deve ser definido como NULL
/// @return 0 se a inicializacao da tabela foi bem sucedida, do contrario -1
/// @complexity O(n) 
int ohtbl_int(OHTbl *htbl, int positions, int (*ht1) (const void *key), int (*ht2) (const void *key), int (*match) (const void *key1, const void *key2), void (*destroy) (void *data));

/// @brief Destroi uma tabela hashing de enderecamento livre
/// @param htbl tabela hashing de enderecamento livre
void ohtbl_destroy(OHTbl *htbl);

/// @brief Insere um elemento na tabela hashing de enderecamento livre
/// @param htbl tabela hashing de enderecamento livre
/// @param data ponteiro para o dado a ser inserido
/// @return 0 se a insercao de elemento e bem sucedida, 1 se o elemento ja estiver na tabela hashing, do contrario -1
/// @complexity O(1) 
int ohtbl_insert(OHTbl *htbl, const void *data);

/// @brief Remove o elemento que coincide com data na tabela hashing de enderecamento livre
/// @param htbl tabela hashing de enderecamento livre
/// @param data ponteiro para o dado a ser removido
/// @return 0 se a remocao for bem sucedida, do contrario -1
/// @complexity O(1)
int ohtbl_remove(OHTbl *htbl, void **data);

/// @brief Determinar se a tabela ja tem o elemento data
/// @param htbl tabela hashing de enderecamento livre
/// @param data ponteiro para o dado a ser pesquisado
/// @return 0 se o elemento for encontrado na tabela hashing, do contrario -1
/// @complexity O(1)
int ohtbl_lookup(const OHTbl *htbl, void **data);

/// @brief Macro que avalia o numero de elementos na tabela hashing de enderecamento livre
#define ohtbl_size(htbl) ((htbl)->size)

#endif