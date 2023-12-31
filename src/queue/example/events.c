#include "events.h"
#include "queue.h"

int receive_event(Queue *events, const Event *event) {
    Event *new_event;

    if ((new_event = (Event *) malloc(sizeof(Event))) == NULL)
        return -1;

    memcpy(new_event, event, sizeof(Event));

    if (queue_enqueue(events, new_event) != 0)
        return -1;
    
    return 0;
}

int process_event(Queue *events, Event *event, int (*dispatch) (Event *event)) {
    Event *event;

    if (queue_size(events) == 0)
        return -1;

    if (queue_dequeue(events, (void **) &event) != 0)
        return -1;

    dispatch(event);
    free(event);

    return 0;
}