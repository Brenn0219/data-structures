#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <memory.h>

/// @brief Estrutura de dados Heap
typedef struct Heap {
    int size;

    int (*compare) (const void *key1, const void *key2);
    void (*destroy) (void *data);

    void **tree;
} Heap;

/// @brief Inicializa o Heap
/// @param heap heap
/// @param compare ponteiro de funcao que compara os nodos. Esta funcao deve retornar 1 se key1 > key2, 0 key1 == ke2 e -1 se key1 < key2
/// @param destroy ponteiro para funcao, remover/liberar os dados que foram alocados dinamicamente. Para uma tabela hasing que contenha dados que nao devem ser liberados, destroy deve ser definido como NULL
/// @complexity O(1)
void heap_init(Heap *heap, int (*compare) (const void *key1, const void *key2), void (*destroy) (void *data));

/// @brief Destroi o heap
/// @param heap heap
/// @complexity O(n)
void heap_destroy(Heap *heap);

/// @brief Insere um nodo no heap 
/// @param heap heap
/// @param data ponteiro para o dado a ser inserido
/// @return 0 se a insercao do nodo for bem sucedida, do contrario -1
/// @complexity O(lg n)
int heap_insert(Heap *heap, const void *data);

/// @brief Extrai o nodo do topo do heap
/// @param heap heap
/// @param data ponteiro para o dado armazenado no nodo que foi extraido
/// @complexity O(lg n)
void heap_extract(Heap *heap, void **data);

/// @brief Macro que avalia o numero de nodos no heap especificado por heap
#define heap_size(heap) ((heap)->size)

#endif