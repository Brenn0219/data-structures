#include <stdlib.h>
#include "parcel.h"
#include "parcels.h"
#include "pqueue.h"

int get_parcel(Pqueue *parcels, Parcel *parcel) {
    Parcel *data;

    if (pqueue_size(parcels) == 0)
        return -1;

    if (pqueue_extract(parcels, (void **) &data) != 0)
        return -1;

    memcpy(parcel, data, sizeof(Parcel));

    return 0;
}

int put_parcel(Pqueue *parcels, Parcel *parcel) {
    Parcel *data;

    if ((data = (Parcel *) malloc(sizeof(Parcel))) != NULL)
        return -1;

    memcpy(data, parcel, sizeof(Parcel));

    if (pqueue_insert(parcels, data) != 0)
        return -1;

    return 0;
}