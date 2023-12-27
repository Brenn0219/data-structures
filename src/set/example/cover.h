#ifndef COVER_H
#define COVER_H

#include "set.h"
#include "list.h"
#include <stdlib.h>

typedef struct Kset {
    void *key;
    Set set;
} Kset;

int cover(Set *memebers, Set *subsets, Set *covering);

#endif