#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "list.h"

/// @brief Estrutura de um Conjunto e a mesma de uma lista encadeada
typedef List Set;

/// @brief Inicializa o conjunto especificado como set. Esta operacao deve ser chamada antes que um conjunto possa ser usado com qualquer outra operacao.
/// @param set conjunto
/// @param match funcao para determinar se dois membros sao iguais
/// @param destroy funcao para liberar dados alocados dinamicamente
/// @complexity O(1)
void set_init(Set *set, int (*match) (const void *key1, const void *key2), void (*destroy) (void *data));

/// @brief Destroi o conjunto especificado como set
/// @param set conjunto
/// @complexity O(1)
#define set_destroy list_destroy

/// @brief Insere um membro no conjunto especificado como set
/// @param set conjunto
/// @param data dado a ser inserido
/// @return 0 se a insercacao do membro for bem sucedida, 1 se o membro ja estiver no conjunto, do contrario -1
/// @complexity O(n)
int set_insert(Set *set, const void *data);

/// @brief Remove o membro que coincida com data no conjunto especificado
/// @param set conjunto
/// @param data aponta pora os dado armazenado no membro removido 
/// @return 0 se a remocao do membro for bem sucedida, do contrario -1
/// @complexity O(n) 
int set_remove(Set *set, void **data);

/// @brief Constroi um conjunto que e a uniao de set1 e set2 
/// @param setu novo conjunto da uniao de set1 e set2
/// @param set1 conjunto
/// @param set2 conjunto
/// @return 0 se a computacao da uniao for bem sucedida, do contrario -1
/// @complexity O(n²) 
int set_union(Set *setu, const Set *set1, const Set *set2);

/// @brief Constroi um conjunto que e a intercacao de set1 e set2 
/// @param setu novo conjunto da intercacao de set1 e set2
/// @param set1 conjunto
/// @param set2 conjunto
/// @return 0 se a computacao da intercao for bem sucedida, do contrario -1
/// @complexity O(n²)
int set_intersection(Set *seti, const Set *set1, const Set *set2);

/// @brief Constroi um conjunto que e a diferenca de set1 e set2 
/// @param setu novo conjunto da diferenca de set1 e set2
/// @param set1 conjunto
/// @param set2 conjunto
/// @return 0 se a computacao da diferenca for bem sucedida, do contrario -1
/// @complexity O(n²)
int set_difference(Set *setd, const Set *set1, const Set *set2);

/// @brief Determina se os dados especificado por data coincidem com um membro do conjunto especificado como set
/// @param set conjunto
/// @param data dado a ser pesquisado
/// @return 1 se o membro for encontrado, do contrario 0
/// @complexity O(n)
int set_is_member(const Set *set, const void *data);

/// @brief Determina se o conjunto especificado por set1 e um subconjunto do conjunto especificado como set2 
/// @param set1 conjunto
/// @param set2 conjunto
/// @return 1 se o conjunto for um subconjunto, do contrario 0
/// @complexity O(n²)
int set_is_subset(const Set *set1, Set *set2);

/// @brief Determina se o conjunto especificado por set1 e igual ao conjunto especificado como set2 
/// @param set1 conjunto
/// @param set2 conjunto
/// @return 1 se os dois conjuntos forem iguais, do contrario 0
/// @complexity O(n²)
int set_is_equal(const Set *set1, const Set *set2);

/// Macro que avalia o número de membros no conjunto especificado por set
#define set_size(set) ((set)->size)

#endif