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
int stack_pop(Stack *stack, void **data);

/// @brief Macro stack_peek fornece uma maneira de inspecionar o elemento no topo de uma pilha sem realmente estourá-lo
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
#define stack_init list_init
#define stack_destroy list_destroy
#define stack_size list_size

#endif