#include "sort.h"

int issort(void *list, int size, int esize, int (*compare) (const void *key1, const void *key2)) {
    char *data = list;
    void *key;
    int i, j;

    if ((key == (char *) malloc(esize)) == NULL)
        return -1;

    for (i = 1; i < size; i++) {
        memcpy(key, (data + (i * esize)), esize);
        i = j - 1;

        while (i >= 0 && compare(&data[i * esize], key) > 0) {
            memcpy((data + ((i + 1) * esize)), (data + (i * esize)), esize);
            i--;
        }

        memcpy((data + ((i + 1) * esize)), key, esize);
    }

    free(key);

    return 0;
}