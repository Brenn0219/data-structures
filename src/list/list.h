#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/// @brief Estrutura para elementos da lista encadeada
typedef struct ListElmt {
    void *data;
    struct ListElmt *next;
} ListElmt;

/// @brief Estrutura da Lista Encadeada
typedef struct List {
    int size;

    int (*match) (const void *key1, const void *key2);
    void (*destroy) (void *data);

    ListElmt *head;
    ListElmt *tail;
} List; 

/// @brief Inicializa a lista encadeada. Esta operacao tem que ser chamada antes de ser usada por qualquer outra operacao.
/// @param list lista encadeada 
/// @param destroy funcao para remover liberar os dados que foram alocados dinamicamente. Para uma lista que contenha dados que nao devem ser liberados, destroy deve ser definido como NULL
/// @complexity O(1)
void list_init(List *list, void (*destroy) (void *data));

/// @brief Destroi a lista encadeada.
/// @param list lista encadeada
/// @complexity O(n), onde n e o numero de elementos da lista
void list_destroy(List *list);

/// @brief Insere um elemento na lista.
/// @param list lista encadeada
/// @param element sentinela que ajuda inserir o dado na lista. Se element e NULL, o novo elemento e inserido na cabeca da lista 
/// @param data dado a ser inserido na lista. E inserido logo apos element
/// @return 0 se a insercao de elemento e bem sucedida, do contrario, -1
/// @complexity O(1)
int list_ins_next(List *list, ListElmt *element, const void *data);

/// @brief Remove um elemento da lista
/// @param list lista encadeada
/// @param element sentinela que ajuda remover o dado na lista. Se element e NULL, o novo elemento e removido na cabeca da lista 
/// @param data dado a ser removido na lista. E removido logo apos element
/// @return 0 se a insercao de elemento e bem sucedida, do contrario, -1
/// @complexity O(1)
int list_rem_next(List *list, ListElmt *element, void **data);

// Macro que avalia o número de elementos na lista encadeada
#define list_size(list) ((list)->size)

// Macro que avalia o elemento no topo da lista encadeada
#define list_head(list) ((list)->head)

// Macro que avalia o elemento no final da lista encadeada
#define list_tail(list) ((list)->tail)

// Macro que determina se o elemento especificado como element está no topo de uma lista encadeada
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

// Macro que determina se o elemento especificado como element está no final de uma lista encadeada
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

// Macro que avalia os dados armazenados no elemento de uma lista encadeada especificada por elemento
#define list_data(element) ((element)->data)

// Macro que avalia o elemento de uma lista encadeada seguindo o elemento especificado por element
#define list_next(element) ((element)->next)

#endif