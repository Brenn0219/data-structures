#ifndef STACK_H
#define STACK_H 

#include <stdlib.h>
#include "list.h"

/// @brief Estrutura de uma Pilha e a mesma de uma lista encadeada
typedef List Stack;

/// @brief Envia um elemento para a pilha especificada por stack. O novo elemento contém um ponteiro para dados, então a memória referenciada pelos dados deve permanecer válida enquanto o elemento permanecer no pilha. É responsabilidade do chamador gerenciar o armazenamento associado aos dados.
/// @param stack ponteiro para uma pilha
/// @param data elemento novo a ser inserido
/// @return 0 se a insercao do elemento for bem sucedidade ou -1 caso contrario.
/// @complexity O(1)
int stack_push(Stack *stack, const void *data);

/// @brief Retira um elemento da pilha especificada por stack. Ao retornar, os dados apontam para os dados armazenados em o elemento que foi exibido. É responsabilidade do chamador gerenciar o armazenamento associado com os dados. 
/// @param stack ponteiro para uma pilha
/// @param data elemento a ser removido
/// @return 0 se a insercao do elemento for bem sucedidade ou -1 caso contrario.
/// @complexity O(1)
int stack_pop(Stack *stack);

/// @brief The stack_init operation initializes a stack so that it can be used in other operations . Since a stack is a linked list and requires the same initialization, stack_init is defined to list_init . The runtime complexity of stack_init is the same as list_init , or O (1).
#define stack_init list_init
/// @brief A operação stack_destroy destrói uma pilha. Como uma pilha é uma lista vinculada e requer sendo destruído da mesma maneira, stack_destroy é definido como list_destroy . A complexidade do tempo de execução de stack_destroy é a mesma de list_destroy , ou O (n ), onde n é o número de elementos na pilha.
#define stack_destroy list_destroy
/// @brief Macro stack_peek fornece uma maneira de inspecionar o elemento no topo de uma pilha sem realmente estourá-lo
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
/// @brief stack_size é avaliado como o tamanho de uma pilha.
#define stack_size list_size

#endif