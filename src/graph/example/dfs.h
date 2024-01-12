#ifndef DFS_H
#define DFE_H

#include "graph.h"

typedef struct DfsVertex {
    void *data;
    VertexColor color;
} DfsVertex;

int dfs(Graph *graph, List *ordered);

#endif