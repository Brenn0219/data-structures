#include "clist.h"

void clist_init(CList *list, void (*destroy) (void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
}

void clist_destroy(CList *list) {
    void *data;

    while (clist_size(list) > 0)  {
        if (clist_remove(list, NULL, (void **) &data) == 0 && list->destroy != NULL)
            list->destroy(data);
    }
    
    memset(list, 0, sizeof(CList));
}

int clist_ins_next(CList *list, CListElmt *element, const void *data) {
    CListElmt *new_element;

    if (element == NULL && clist_size(list) != 0)
        return -1;

    if (new_element = (CListElmt *) malloc(sizeof(CListElmt)) == NULL)
        return -1;

    new_element->data = (void *) data;

    if (clist_size(list) == 0) {
        new_element->next = new_element;
        new_element->prev = new_element;
        list->head = new_element;
    } else {
        if (element == NULL)
            element = list->head;

        new_element->next = element->next;
        element->next->prev = new_element;
        new_element->prev = element;
        element->next = new_element;
    }

    list->size++;

    return 0;
}

int clist_ins_prev(CList *list, CListElmt *element, const void *data) {
    CListElmt *new_element;

    if (element == NULL && clist_size(list) != 0)
        return -1;

    if (new_element = (CListElmt *) malloc(sizeof(CListElmt)) == NULL)
        return -1;

    new_element->data = (void *) data;

    if (clist_size(list) == 0) {
        new_element->next = new_element;
        new_element->prev = new_element;
        list->head = new_element;
    } else {
        if (element == NULL)
            element = list->head;

        new_element->prev = element->prev;
        element->prev->next = new_element;
        new_element->next = element;
        element->prev = new_element;
    }

    list->size++;

    return 0;
}

int clist_remove(CList *list, CListElmt *element, void **data) {
    CListElmt *old_element;

    if (clist_size(list) == 0)
        return -1;

    *data = element->next->data;

    if (element == NULL)
        element = list->head;

    if (clist_size(list) > 1) {
        old_element = element->next;
        element->next = old_element->next;
        old_element->next->prev = element;
    } else 
        old_element = element;
    
    old_element->next = NULL;
    old_element->prev = NULL;

    free(old_element);
    list->size--;

    return 0;
}