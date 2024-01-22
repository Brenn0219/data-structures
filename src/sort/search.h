#ifndef BISEARCH_H
#define BISEARCH_H

#include <stdlib.h>
#include <memory.h>

int bisearch(void *sorted, void *target, int size, int esize, int (*compare) (const void *key1, const void *key2));

#endif