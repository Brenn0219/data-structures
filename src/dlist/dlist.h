#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

/// @brief Elementos da lista de encadeamento duplo
typedef struct DListElmt {
    void *data;
    struct DListElmt *prev;
    struct DListElmt *next;
} DListElmt;

/// @brief Estrutura da Lista Duplamente Encadeada
typedef struct DList {
    int size;

    int (*match) (const void *key1, const void *key2);
    void (*destroy) (void *data);

    DListElmt *head;
    DListElmt *tail;
} DList;

/// @brief Inicializa a lista duplamente encadeada. Esta operacao tem que ser chamada antes de ser usada por qualquer outra operacao. 
/// @param list lista duplamente encadeada
/// @param destroy funcao para remover liberar os dados que foram alocados dinamicamente. Para uma lista que contenha dados que nao devem ser liberados, destroy deve ser definido como NULL
/// @complexity O(1)
void dlist_init(DList *list, void (*destroy) (void *data));

/// @brief Destroi a lista duplamente encadeada.
/// @param list lista duplamente encadeada
/// @complexity O(n), onde n e o numero de elementos da lista
void dlist_destroy(DList *list);

/// @brief Insere um elemento na lista.
/// @param list lista duplamente encadeada
/// @param element sentinela que ajuda inserir o dado na lista. Se element e NULL, o novo elemento e inserido na cabeca da lista 
/// @param data dado a ser inserido na lista. E inserido logo apos element
/// @return 0 se a insercao de elemento e bem sucedida, do contrario, -1
/// @complexity O(1)
int dlist_ins_next(DList *list, DListElmt *element, const void *data);

/// @brief Remove um elemento da lista
/// @param list lista duplamente encadeada
/// @param element sentinela que ajuda remover o dado na lista. Se element e NULL, o novo elemento e removido na cabeca da lista 
/// @param data dado a ser removido na lista. E removido logo apos element
/// @return 0 se a insercao de elemento e bem sucedida, do contrario, -1
/// @complexity O(1)
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);

/// @brief Remove um elemento da lista
/// @param list lista encadeada
/// @param element sentinela que ajuda remover o dado na lista. Se element e NULL, o novo elemento e removido na cabeca da lista 
/// @param data dado a ser removido na lista. E removido logo apos element
/// @return 0 se a insercao de elemento e bem sucedida, do contrario, -1
/// @complexity O(1)
int dlist_remove(DList *list, DListElmt *element, void **data);

// Macro que avalia o número de elementos na lista duplamente encadeada
#define dlist_size(list) ((list)->size)

// Macro que avalia o elemento no topo da lista duplamente encadeada
#define dlist_head(list) ((list)->head)

// Macro que avalia o elemento no final da lista duplamente encadeada
#define dlist_tail(list) ((list)->tail)

// Macro que determina se o elemento especificado como element está no topo de uma lista duplamente encadeada
#define dlist_is_head(list, element) ((element) == (list)->head ? 1 : 0)

// Macro que determina se o elemento especificado como element está no final de uma lista duplamente encadeada
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)

// Macro que avalia os dados armazenados no elemento de uma lista duplamente encadeada especificada por elemento
#define dlist_data(element) ((element)->data)

// Macro que avalia o elemento de uma lista duplamente encadeada precedente ao elemento especificado por element
#define dlist_next(element) ((element)->next)

#endif