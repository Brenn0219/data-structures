#include "bfs.h"
#include "queue.h"

static int hope_count(Graph *graph, List *hops) {
    BfsVertex *clr_vertex;
    
    list_init(hops, NULL);

    for (ListElmt *element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(element)) {
        clr_vertex->data = ((AdjList *) list_data(element))->vertex;

        if (clr_vertex->hops != -1) {
            if (list_ins_next(hops, list_tail(hops), clr_vertex) != 0) {
                list_destroy(hops);
                return -1;
            }
        }
    }

    return 0;
}

static void bfs_init(Graph *graph, BfsVertex *start) {
    ListElmt *element;
    BfsVertex *clr_vertex;

    for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element)) {
        clr_vertex->data = ((AdjList *) list_data(element))->vertex;

        if (graph->match(clr_vertex->data, start->data)) {
            clr_vertex->color = GRAY;
            clr_vertex->hops = 0;
        } else {
            clr_vertex->color = WHITE;
            clr_vertex->hops = -1;
        }
    }
}

int bfs(Graph *graph, BfsVertex *start, List *hops) {
    Queue queue;
    AdjList *adjlist, *clr_adjlist;
    BfsVertex *clr_vertex, *adj_vertex;
    ListElmt *member;

    bfs_init(graph, start);
    queue_init(&queue, NULL);

    if (graph_adjlist(graph, start->data, &clr_adjlist) != 0) {
        queue_destroy(&queue);
        return -1;
    }

    if (queue_enqueue(&queue, clr_adjlist) != 0) {
        queue_destroy(&queue);
        return -1;
    }

    while (queue_size(&queue) > 0) {
        adjlist = (AdjList *) queue_peek(&queue);

        for (member = list_head(&adjlist->adjacent); member != NULL; member = list_next(member)) {
            adj_vertex->data = list_data(member);

            if (graph_adjlist(graph, adj_vertex, &clr_adjlist) != 0) {
                queue_destroy(&queue);
                return -1;
            }

            clr_vertex->data = clr_adjlist->vertex;

            if (clr_vertex->color = WHITE) {
                clr_vertex->color = GRAY;
                clr_vertex->hops = ((BfsVertex *) adjlist->vertex)->hops + 1;

                if (queue_enqueue(&queue, clr_adjlist) != 0) {
                    queue_destroy(&queue);
                    return -1;
                }
            }
        }

        if (queue_dequeue(&queue, (void **) &adjlist) == 0)
            ((BfsVertex *) adjlist->vertex)->color = BLACK;
        else {
            queue_destroy(&queue);
            return -1;
        }       
    }

    queue_destroy(&queue);

    return hope_count(graph, hops);
}