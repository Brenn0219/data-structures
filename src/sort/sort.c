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

    return k;
}

int qksort(void * list, int size, int esize, int i, int k, int (*compare) (const void *key1, const void *key2)) {
    int j;

    while (i < k) {
        if ((j = partition(list, size, esize, i, k, compare)) < 0)
            return -1;
        
        if (qksort(list, size, esize, i, j, compare) < 0)
            return -1;

        if (qksort(list, size, esize, j + 1, k, compare) < 0)
            return -1;
    }

    return 0;
}

static int merge(void *list, int esize, int i, int j, int k, int (*compare) (const void *key1, const void *key2)) {
    char *data = list, *join;
    int ipos, jpos, mpos;

    ipos = i;
    jpos = j + 1;
    mpos = 0;

    if ((join = (char *) malloc(esize * (k - i + 1))) == NULL)
        return -1;

    while (ipos <= j || jpos <= k) {
        if (ipos > j) {
            while (jpos <= k) {
                memcpy(&join[mpos * esize], &data[jpos * esize], esize);
                jpos++;
                mpos++;
            }

            continue;
        } else if (jpos > k) {
            while (ipos <= j) {
                memcpy(&data[mpos * esize], &join[ipos * esize], esize);
                ipos++;
                mpos++;
            }
            
            continue;
        } else {
            if (compare(&data[ipos *esize], &join[jpos * esize]) < 0) 
                memcpy(&data[mpos * esize], &join[ipos * esize], esize);
            else 
                memcpy(&data[mpos * esize], &join[jpos * esize], esize);

            ipos++;
            mpos++;
        }
    }

    memcpy(&data[i * esize], join, esize * ((k - i) + 1));
    free(join);

    return 0;
}

int mgsort(void * list, int size, int esize, int i, int k, int (*compare) (const void *key1, const void *key2)) {
    int j;

    if (i < k) {
        j = (int) ((i + k - 1) / 2);

        if (mgsort(list, size, esize, i, j, compare) != 0)
            return -1;

        if (mgsort(list, size, esize, j + 1, k, compare) != 0)
            return -1;

        if (merge(list, esize, i, j, k, compare) != 0)
            return -1;
    }

    return 0;
}

int ctsort(int *data, int size, int k) {
    int *counts, *temp, i;

    if ((counts = (int *) malloc(k * sizeof(int))) == NULL)
        return -1;
    
    if ((temp = (int *) malloc(size * sizeof(int))) == NULL)
        return -1;

    for (i = 0; i < k; i++) 
        counts[i] = 0;
    
    for (i = 0; i < size; i++)
        counts[data[i]] = counts[data[i]] + 1;

    for (i = 1; i < size; i++)
        counts[i] = counts[i] + counts[i - 1];

    for (i = size - 1; i >= 0; i--) {
        temp[counts[data[i]] - 1] = data[i];
        counts[data[i]] = counts[data[i]] - 1;
    }

    memcpy(data, temp, size * sizeof(int));

    free(temp);
    free(counts);

    return 0;
}

int rxsort(int *data, int size, int p, int k) {
    int *counts, *temp, pval, index;

    if ((counts = (int *) malloc(k * sizeof(int))) == NULL)
        return -1;
    
    if ((temp = (int *) malloc(size * sizeof(int))) == NULL)
        return -1;

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < k; j++) 
            counts[j] = 0;

        pval = (int) pow((double) k, (double) i);

        for (int j = 0; j < size; j++) {
            index = (int) (data[j] / pval) % k;
            counts[index] = counts[index] + 1; 
        }

        for (int j = 1; j < k; j++) 
            counts[j] = counts[j] + counts[j - 1];

        for (int j = size - 1; j >= 0; j--) {
            index = (int) (data[j] / pval) % k;
            temp[counts[index] - 1] = data[j];
            counts[index] = counts[index] - 1;
        }
    }

    memcpy(data, temp, size * sizeof(int));

    free(counts);
    free(temp);

    return 0;
}