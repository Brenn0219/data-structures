#ifndef GRAPH_H
#define GRAPH_H

#include "set.h"
#include <memory.h>

/// @brief Estrutura de dados Grafos
typedef struct Graph {
    int vcount; 
    int ecount;

    int (*match) (const void *first_key, const void *second_key);
    void (*destroy) (void *data);

    List adjlists;
} Graph;

/// @brief Estrutura de dados Lista Adjacencia são usadas para grafos esparsos, ou seja, grafos nos quais o número de arestas é menor que o número de vértices ao quadrado.
typedef struct AdjList {
    void *vertex;
    Set adjacent;
} AdjList; 

typedef enum VertexColor {WHITE, GRAY, BLACK} VertexColor;

/// @brief Inicializa o grafico especificado 
/// @param graph ponteiro para um grafo
/// @param match ponteiro para funcao de comparacao para determinar se dois vertices sao iguais. Este argumento deve retornar 1 se key1 for igual a key2, do contrario 0
/// @param destroy ponteiro para funcao de liberacao das estruturas alocadas dinamicamente nas listas
/// @complexity O(1)
void graph_init(Graph *graph, int (*match) (const void *first_key, const void *second_key), void (*destroy) (void *data));

/// @brief Destrói o grafo 
/// @param graph ponteiro para um grafo
/// @complexity O(V + E), onde V e o numero de vertices no grafo e E e o numero de arestas
void graph_destroy(Graph *graph);

/// @brief Insere um vértice no gráfico 
/// @param graph ponteiro para um grafo
/// @param data ponteiro para o novo elemento a ser inserido na lista
/// @return 0 se a inserção da aresta for bem-sucedida, 1 se a aresta já existir ou -1 caso contrário
/// @complexity O(V), onde V o numero de vertices
int graph_insert_vertex(Graph *graph, const void *data);

/// @brief Insere uma aresta do vértice especificado por data1 até o vértice especificado por data2 no grafo 
/// @param graph ponteiro para um grafo
/// @param data1 vertice incidente
/// @param data2 vertice sucessor
/// @return 0 se a remocao da aresta for bem-sucedidae, -1 caso contrário.
/// @complexity O(V), onde V o numero de vertices
int graph_insert_edge(Graph *graph, const void *data1, const void *data2);

/// @brief Remove os dados de correspondência de vértices do gráfico especificado por graph 
/// @param graph ponteiro para um grafo
/// @param data vertice a ser removido
/// @return 0 se a inserção da aresta for bem-sucedida, 1 se a aresta já existir ou -1 caso contrário.
/// @complexity O(V + E), onde V e o numero de vertices no grafo e E e o numero de arestas
int graph_remove_vertex(Graph *graph, void **data);

/// @brief Remove a borda de v para w no grafo
/// @param graph ponteiro para um grafo
/// @param v vertice incidente
/// @param w vertice sucessor
/// @return 0 se a inserção da aresta for bem-sucedida, 1 se a aresta já existir ou -1 caso contrário.
/// @complexity O(V), onde V o numero de vertices
int graph_remove_edge(Graph *graph, void *v, void *w);

/// @brief Recupera vértices adjacentes ao vértice especificado pelos dados em graph 
/// @param graph ponteiro para um grafo
/// @param data vertice 
/// @param adjlist lista adjacente do vertice/data
/// @return 1 se o segundo vértice for adjacente ao primeiro vértice ou caso contrário.
/// @complexity O(V), onde V o numero de vertices
int graph_adjlist(const Graph *graph, const void *data, AdjList **adjlist);

/// @brief Verifica se um vertice e adjacente a outro
/// @param graph ponteiro para um grafo
/// @param data1 vertice
/// @param data2 vertice adjacente
/// @return 1 ser for adjacente, 0 se nao for e -1 se houver erro
int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2);

// Macro que retorna a lista encadeada utilizada no grafo
#define graph_adjlists(graph) ((graph)->adjlists)

// Macro que avalia o número de vértices no gráfico especificado por graph.
#define graph_vcount(graph) ((graph)->vcount)

// Macro que avalia o número de arestas no gráfico especificado por gráfico.
#define graph_ecount(graph) ((graph)->ecount)

#endif