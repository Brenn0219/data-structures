#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

/// @brief Elementos da lista circular
typedef struct CListElmt {
    void *data;
    struct CListElmt *prev;
    struct CListElmt *next;
} CListElmt;

/// @brief Estrutura da Lista Circular
typedef struct CList {
    int size;

    int (*match) (const void *key1, const void *key2);
    void (*destroy) (void *data);

    CListElmt *head;
} CList;

/// @brief Inicializa a lista circular. Esta operacao tem que ser chamada antes de ser usada por qualquer outra operacao. 
/// @param list lista circular
/// @param destroy funcao para remover liberar os dados que foram alocados dinamicamente. Para uma lista que contenha dados que nao devem ser liberados, destroy deve ser definido como NULL
/// @complexity O(1)
void clist_init(CList *list, void (*destroy) (void *data));

/// @brief Destroi a lista circular.
/// @param list lista circular
/// @complexity O(n), onde n e o numero de elementos da lista
void clist_destroy(CList *list);

/// @brief Insere um elemento na lista.
/// @param list lista circular
/// @param element sentinela que ajuda inserir o dado na lista. Se element e NULL, o novo elemento e inserido na cabeca da lista 
/// @param data dado a ser inserido na lista. E inserido logo apos element
/// @return 0 se a insercao de elemento e bem sucedida, do contrario, -1
/// @complexity O(1)
int clist_ins_next(CList *list, CListElmt *element, const void *data);

/// @brief Remove um elemento da lista
/// @param list lista circular
/// @param element sentinela que ajuda remover o dado na lista. Se element e NULL, o novo elemento e removido na cabeca da lista 
/// @param data dado a ser removido na lista. E removido logo apos element
/// @return 0 se a insercao de elemento e bem sucedida, do contrario, -1
/// @complexity O(1)
int clist_ins_prev(CList *list, CListElmt *element, const void *data);

/// @brief Remove um elemento da lista
/// @param list lista encadeada
/// @param element sentinela que ajuda remover o dado na lista. Se element e NULL, o novo elemento e removido na cabeca da lista 
/// @param data dado a ser removido na lista. E removido logo apos element
/// @return 0 se a insercao de elemento e bem sucedida, do contrario, -1
/// @complexity O(1)
int clist_remove(CList *list, CListElmt *element, void **data);

// Macro que avalia o número de elementos na lista circular
#define clist_size(list) ((list)->size)

// Macro que avalia o elemento no topo da lista circular
#define clist_head(list) ((list)->head)

// Macro que avalia o elemento no final da lista circular
#define clist_tail(list) ((list)->tail)

// Macro que determina se o elemento especificado como element está no topo de uma lista circular
#define clist_is_head(list, element) ((element) == (list)->head ? 1 : 0)

// Macro que determina se o elemento especificado como element está no final de uma lista circular
#define clist_is_tail(element) ((element)->next == NULL ? 1 : 0)

// Macro que avalia os dados armazenados no elemento de uma lista circular especificada por elemento
#define clist_data(element) ((element)->data)

// Macro que avalia o elemento de uma lista circular segue o elemento especificado por element
#define clist_next(element) ((element)->next)

// Macro que avalia o elemento de uma lista circular precede o elemento especificado por element
#define clist_prev(element) ((element)->prev)

#endif