#include "dfs.h"

int dfs_main(Graph *graph, AdjList *adjlist, List *ordered) {
    AdjList *clr_adjlist;
    DfsVertex *clr_vertex, *adj_vertex;
    ListElmt *member;

    ((DfsVertex *) adjlist->vertex)->color = GRAY;

    for (member = list_head(&adjlist->adjacent); member != NULL; member = list_next(member)) {
        adj_vertex->data = list_data(member);

        if (graph_adjlist(graph, adj_vertex->data, &clr_adjlist) != 0)
            return -1;

        clr_vertex->data = clr_adjlist->vertex;
        
        if (clr_vertex->color == WHITE && (dfs_main(graph, clr_adjlist, ordered)) != 0)
            return -1;
    }

    ((DfsVertex *) adjlist->vertex)->color = BLACK;

    if (list_ins_next(ordered, NULL, adjlist->vertex) != 0)
        return -1;

    return 0;
}

int dfs(Graph *graph, List *ordered) {
    DfsVertex *vertex;
    ListElmt *element;

    for (element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(element)) {
        vertex->data = ((AdjList *) list_data(element))->vertex;
        vertex->color = WHITE;
    }

    list_init(ordered, NULL);

    for (element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(element)) {
        vertex->data = ((AdjList *) list_data(element))->vertex;

        if (vertex->color == WHITE) {
            if (dfs_main(graph, (AdjList *) list_data(element), ordered) != 0) {
                list_destroy(ordered);
                return -1;
            }
        }
    }

    return 0;
}