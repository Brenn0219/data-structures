#include "othbl.h"

static char vacated;

int ohtbl_int(OHTbl *htbl, int positions, int (*ht1) (const void *key), int (*ht2) (const void *key), int (*match) (const void *key1, const void *key2), void (*destroy) (void *data)) {
    int i;

    if ((htbl->table = (void **) malloc(positions * sizeof(void *))) == NULL)
        return -1;

    htbl->positions = positions;

    for (i = 0; i < htbl->positions; i++)
        htbl->table[i] = NULL;

    htbl->vacated = &vacated;
    htbl->ht1 = ht1;
    htbl->ht2 = ht2;
    htbl->match = match;
    htbl->destroy = destroy;
    htbl->size = 0;

    return 0;
}

void ohtbl_destroy(OHTbl *htbl) {
    int i;

    if (htbl->destroy != NULL) {
        for (i = 0; i < htbl->positions; i++) {
            if (htbl->table[i] != NULL && htbl->table[i] != htbl->vacated)
                htbl->destroy(htbl->table[i]);
        }
    }

    free(htbl->table);
    memset(htbl, 0, sizeof(OHTbl));
}

int ohtbl_insert(OHTbl *htbl, const void *data) {
    void *temp;
    int position, i;

    if (htbl->size == htbl->positions)
        return -1;

    temp = (void *) data;

    if (ohtbl_lookup(htbl, &temp) == 0)
        return 1;

    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->ht1(data) + (i * htbl->ht2(data))) % htbl->positions;

        if (htbl->table[position] == NULL || htbl->table[position] == htbl->vacated) {
            htbl->table[position] = (void *) data;
            htbl->size++;

            return 0;
        }
    }

    return -1;
}

int ohtbl_remove(OHTbl *htbl, void **data) {
    int position, i;

    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->ht1(data) + (i * htbl->ht2(data))) % htbl->positions;

        if (htbl->table[position] == NULL)
            return -1;
        else if (htbl->table[position] == htbl->vacated)
            continue;
        else if (htbl->match(htbl->table[position], *data)) {
            *data = htbl->table[position];
            htbl->table[position] = htbl->vacated;
            htbl->size--;

            return 0;
        }       
    }

    return -1;
}

int ohtbl_lookup(const OHTbl *htbl, void **data) {
    int position, i;

    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->ht1(data) + (i * htbl->ht2(data))) % htbl->positions;

        if (htbl->table[position] == NULL)
            return -1;
        else if (htbl->match(htbl->table[position], *data)) {
            *data = htbl->table[position];
            return 0;
        }       
    }

    return -1;   
}