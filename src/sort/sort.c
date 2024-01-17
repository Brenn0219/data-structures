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

static int compare_int(const void *int1, const void *int2) {
    if (*(const int *) int1 > *(const int *) int2) {
        return 1;
    } else if (*(const int *) int1 < *(const int *) int2) 
        return -1;
    else 
        return 0;
}

static int partition(void * list, int size, int esize, int i, int k, int (*compare) (const void *key1, const void *key2)) {
    char *data = list;
    void *pval, *temp;
    int r[3];

    if ((pval = malloc(esize)) == NULL)
        return -1;

    if ((temp = malloc(esize)) == NULL) {
        free(pval);
        return -1;
    }

    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;

    issort(r, 3, sizeof(int), compare_int);
    memcpy(pval, &data[r[1] * esize], esize);

    i--;
    k++;

    while (1) {
        do {
            k--;
        } while (compare(&data[k * esize], pval) > 0);
        
        do {
            i++;
        } while (compare(&data[i * esize], pval) < 0);

        if (i >= k)
            break;
        else {
            memcpy(temp, &data[i * esize], esize);
            memcpy(&data[i * esize], &data[k * esize], esize);
            memcpy(&data[k * esize], temp, esize);
        }
    }

    free(pval);
    free(temp);

    return 0;
}

int qksort(void * list, int size, int esize, int i, int k, int (*compare) (const void *key1, const void *key2)) {
    int j;

    while (i < k) {
        if ((j = partition(list, size, esize, i, k, compare)) < 0)
            return -1;
        
        if (qksort(list, size, esize, i, j, compare) < 0)
            return -1;

        i = j + 1;
    }

    return 0;
}