#ifndef BISEARCH_H
#define BISEARCH_H

#include <stdlib.h>
#include <memory.h>

/// @brief Pesquisa Binaria
/// @param sorted array ja ordenado
/// @param target dado a ser pesquisado
/// @param size total de dados do array
/// @param esize tamanho do dado
/// @param compare funcao de comparacao dos dados. esta funcao deve retorar 1 se key1 > key2, 0 se key1 == key2 e -1 se key1 < key2
/// @return indice do alvo, caso seja encontrado, do contrario -1
/// @complexity O(lg n)
int bisearch(void *sorted, void *target, int size, int esize, int (*compare) (const void *key1, const void *key2));

#endif