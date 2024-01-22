#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <memory.h>

/// @brief Ordenacao por Insercao
/// @param list array de dados
/// @param size quantidade total dos dados
/// @param esize tamanho do dado
/// @param compare funcao de comparacao entre dois dados. Retorna 1 se key1 > key2, 0 key1 == key2 e -1 se key1 < key2
/// @return 0 se a classsificacao for bem sucedida, do contrario -1
/// @complexity O(n²)
int issort(void *list, int size, int esize, int (*compare) (const void *key1, const void *key2));

/// @brief Ordenacao por QuickSort
/// @param list array de dados
/// @param size quantidade total dos dados
/// @param esize tamanho do dado
/// @param i define a parte que esta sendo classificada a esquerda, inicialmente deve ser 0
/// @param k define a parte que esta sendo classificada a direita, inicialmente deve ser size - 1
/// @param compare funcao de comparacao entre dois dados. Retorna 1 se key1 > key2, 0 key1 == key2 e -1 se key1 < key2
/// @return 0 se a classsificacao for bem sucedida, do contrario -1
/// @complexity O(n lg n)
int qksort(void * list, int size, int esize, int i, int k, int (*compare) (const void *key1, const void *key2)); 

/// @brief Ordenacao por MergeSort
/// @param list array de dados
/// @param size quantidade total dos dados
/// @param esize tamanho do dado
/// @param i define a parte que esta sendo classificada a esquerda, inicialmente deve ser 0
/// @param k define a parte que esta sendo classificada a direita, inicialmente deve ser size - 1
/// @param compare funcao de comparacao entre dois dados. Retorna 1 se key1 > key2, 0 key1 == key2 e -1 se key1 < key2
/// @return 0 se a classsificacao for bem sucedida, do contrario -1
/// @complexity O(n lg n)
int mgsort(void * list, int size, int esize, int i, int k, int (*compare) (const void *key1, const void *key2));

/// @brief Ordenacao por Contagem
/// @param data array de dados
/// @param size tamanho do array
/// @param k numero maximo de inteiros em data
/// @return 0 se a classsificacao for bem sucedida, do contrario -1
/// @complexity O(n lg n)
int ctsort(int *data, int size, int k);

#endif