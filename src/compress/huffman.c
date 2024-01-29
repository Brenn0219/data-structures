#pragma once

#include <limits.h>

#include "bit.h"
#include "bitree.h"
#include "compress.h"
#include "pqueue.h"

/// @brief comparar frequencias armazenadas nos nodos de raiz de duas arvores binarias
/// @param tree1 primeira arvore
/// @param tree2 segunda arvore
/// @return se root1 < root2 retorna 1, root1 > root2 retorna -1, se nao retorna 0
/// @complexity O(1) 
static int compare_freq(const void *tree1, const void *tree2) {
    HuffNode *root1, *root2;

    root1 = (HuffNode *) bitree_data(bitree_root((const BiTree *) tree1)); 
    root2 = (HuffNode *) bitree_data(bitree_root((const BiTree *) tree2)); 

    if (root1->freq < root2->freq)
        return 1;
    else if (root1->freq > root2->freq)
        return -1;
    else 
        return 0;
}

/// @brief destruir e liberar uma arvore binaria de fila prioritaria de arvore
/// @param tree arvore
/// @complexity O(lg n)
static void destroy_tree(void *tree) {
    bitree_destroy(tree);
    free(tree);
}

/// @brief construir a arvore de simbolos de huffman
/// @param freqs frequencia de cada simbolo
/// @param tree arovre
/// @return 0 caso a construcao da arvore for bem  sucedida, caso contrario -1
static int build_tree(int *freqs, BiTree **tree) {
    BiTree *init, *merge, *left, *right;
    Pqueue pqueue;
    HuffNode *data;
    int size;

    // inicializar a fila prioritaria de arvores binarias
    *tree = NULL;
    pqueue_init(&pqueue, compare_freq, destroy_tree);

    for (int i = 0; i <= UCHAR_MAX; i++) {
        if (freqs[i] != 0) {
            // montar arvore binaria para o simbolo atual e sua frequencia 
            if ((init = (BiTree *) malloc(sizeof(BiTree))) == NULL) {
                pqueue_destroy(&pqueue);
                return -1;
            }

            bitree_init(init, destroy_tree);

            if ((data = (HuffNode *) malloc(sizeof(HuffNode))) == NULL) {
                pqueue_destroy(&pqueue);
                return -1;
            }

            data->symbol = i;
            data->freq = freqs[i];

            if (bitree_ins_left(init, NULL, data) != 0) {
                free(data);
                destroy_tree(init);
                pqueue_destroy(&pqueue);
                return -1;
            }

            // inserir arvore binaria na fila prioritaria
            if (pqueue_insert(&pqueue, init) != 0) {
                destroy_tree(init);
                pqueue_destroy(&pqueue);
                return -1;
            }
        }
    }

    // construir arvore Huffman atraves da juncao de arvores na fila prioritaria 
    size = pqueue_size(&pqueue);

    for (int i = 0; i < size; i++) {
        // alocar armazenagem para a proxim arvore unida
        if ((merge = (BiTree *) malloc(sizeof(BiTree))) == NULL) {
            pqueue_destroy(&pqueue);
            return -1;
        }

        // extarir as duas arvores cujos nodos de raiz tem as menores frequencias
        if ((pqueue_extract(&pqueue, (void **) &left)) != 0) {
            pqueue_destroy(&pqueue);
            free(merge);
            return -1;
        }

        if ((pqueue_extract(&pqueue, (void **) &right)) != 0) {
            pqueue_destroy(&pqueue);
            free(merge);
            return -1;
        }

        // alocar armazenagem para os dados no nodo de raiz da arvore que foi unida
        if ((data = (HuffNode *) malloc(sizeof(HuffNode))) == NULL) {
            pqueue_destroy(&pqueue);
            free(merge);
            free(data);
            return -1;
        } 

        memset(data, 0, sizeof(HuffNode));

        // somar as frequencias nos nodos de raiz das arvores sendo unidas
        data->freq = ((HuffNode *) bitree_data(bitree_root(left)))->freq + ((HuffNode *) bitree_data(bitree_root(right)))->freq;

        // unir as duas arvores
        if (bitree_merge(merge, left, right, data) != 0) {
            pqueue_destroy(&pqueue);
            free(merge);
            free(data);
            return -1;
        }

        // inserir arvore unida na fila prioritaria e liberar as outras
        if (pqueue_insert(&pqueue, merge) != 0) {
            pqueue_destroy(&pqueue);
            destroy_tree(merge);
            return -1;
        }

        free(left);
        free(right);
    }

    // a ultima arovre na fila prioritaria e arvore de huffman
    if (pqueue_extract(&pqueue, (void **) tree) != 0) {
        pqueue_destroy(&pqueue);
        return -1;
    }

    return 0;
}

