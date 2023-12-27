#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "list.h"

/// @brief Estrutura de uma Fila e a mesma de uma lista encadeada
typedef List Queue;

/// @brief Enfileira um elemento no final da fila especificada por queue. O novo elemento contém um ponteiro para dados, então a memória referenciada por dados deve permanecer válida enquanto o elemento permanece na fila. É responsabilidade do chamador gerenciar o armazenamento associado ao dados.
/// @param queue ponteiro para uma fila
/// @param data elemento novo a ser inserido
/// @return 0 se a insercao do elemento for bem sucedidade ou -1 caso contrario.
/// @complexity O(1)
int queue_enqueue(Queue *queue, const void *data);

/// @brief Remove um elemento do início da fila especificada por queue. Ao retornar, os dados apontam para os dados armazenados no elemento que foi retirado da fila. É responsabilidade do chamador gerenciar o armazenamento associado aos dados.
/// @param queue ponteiro para uma fila
/// @return 0 se a insercao do elemento for bem sucedidade ou -1 caso contrario.
/// @complexity O(1)
int queue_dequeue(Queue *queue, void **data);

/// @brief Macro stack_peek fornece uma maneira de inspecionar o elemento no topo de uma fila sem realmente estourá-lo
#define queue_peek(queue) ((queue)-> head == NULL ? NULL : (queue)->head->data)
#define queue_init list_init
#define queue_destroy list_destroy
#define queue_size list_size

#endif