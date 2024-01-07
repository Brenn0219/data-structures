#ifndef PQUEUE_H
#define PQUEUE_H

#include "heap.h"

typedef Heap Pqueue;

#define pqueue_destroy heap_destroy
#define pqueue_insert heap_insert
#define pqueue_extract heap_extract
#define pqueue_size heap_size
#define pqueue_peek(pqueue) ((pqueue)->tree == NULL ? NULL : (pqueue)->tree[0])

#endif