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

#endif