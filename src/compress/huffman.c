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

/// @brief construir a tabela de simbolso de huffman
/// @param node nodo de um simbolo da arvore de simbolo de huffman
/// @param code codigo do simbolo
/// @param size tamanho do simbolo
/// @param table tabela
static void build_table(BiTreeNode *node, unsigned short code, unsigned int size, HuffCode *table) {
    if (!bitree_is_eob(node)) {
        // mover para a esquerda e anexar 0 ao codigo atual
        if (!bitree_is_eob(bitree_left(node)))
            build_table(bitree_left(node), code << 1, size + 1, table);

        // mover para direita e anexar 1 ao codigo atual
        if (!bitree_is_eob(bitree_right(node)))
            build_table(bitree_right(node), code << 1 | 0x001, size + 1, table);

        if (bitree_is_eob(bitree_left(node)) && bitree_is_eob(bitree_right(node))) {
            // assegurar que o codigo atual esta em formato big-endian
            code = htons(code);

            // designar codigo atual para o simbolo no nodo de folha
            table[((HuffNode *) bitree_data(node))->symbol].used = 1;
            table[((HuffNode *) bitree_data(node))->symbol].code = code;
            table[((HuffNode *) bitree_data(node))->symbol].size = size;
        }
    }
}

int huffman_compress(const unsigned char *original, unsigned char **compressed, int size) {
    BiTree *tree;
    HuffCode table[UCHAR_MAX + 1];
    int freqs[UCHAR_MAX + 1], max, scale, hsize, ipos, opos, cpos;
    unsigned char *comp, temp;

    // inicialmente nao ha buffer de dados comprimidos
    *compressed = NULL;

    // obter frequencia de cada simbolo nos dados originais
    for (int i = 0; i <= UCHAR_MAX; i++) 
        freqs[i] = 0;
    
    ipos = 0;

    if (size > 0) {
        while (ipos < size) 
            freqs[original[ipos++]]++;
    }

    // graduar frequencias para caberem em um byte
    max = UCHAR_MAX;

    for (int i = 0; i <= UCHAR_MAX; i++) {
        if (freqs[i] > max)
            max = freqs[i];
    }

    for (int i = 0; i <= UCHAR_MAX; i++) {
        scale = (int) (freqs[i] / ((double) max / (double) UCHAR_MAX));

        if (scale == 0 && freqs[i] != 0)
            freqs[i] = 1;
        else 
            freqs[i] = scale;
    }

    // construir a arvore de huffman e a tabela de codigos para os dados
    if (build_tree(freqs, &tree) != 0)
        return -1;

    for (int i = 0; i <= UCHAR_MAX; i++) 
        memset(&table[i], 0, sizeof(HuffCode));
    
    build_table(bitree_root(tree), 0x0000, 0, table);
    destroy_tree(tree);

    // escrever informacao de cabecalho
    hsize = sizeof(int) + (UCHAR_MAX + 1);

    if ((comp = (unsigned char *) malloc(hsize)) == NULL)
        return -1;

    memcpy(comp, &size, sizeof(int));

    for (int i = 0; i <= UCHAR_MAX; i++) {
        comp[sizeof(int) + i] = (unsigned char) freqs[i];

        // comprimir dados
        ipos = 0;
        opos = hsize * 8;

        while (ipos < size) {
            // tomar o proximo simbolo nos dados originais
            i = original[ipos];

            // gravar codigo do simbolo para o buffer dos dados comprimidos
            for (int j = 0; j < table[i].size; i++) {
                if (opos % 8 == 0) {
                    // alocar outro bytes para o buffer de dados comprimidos
                    if ((temp = (unsigned char *) realloc(comp, (opos / 8 + 1))) == NULL) {
                        free(comp);
                        return -1;
                    }

                    comp = temp;
                }

                cpos = (sizeof(short) * 8) - table[i].size + j;
                bit_set(comp, opos, bit_get((unsigned char *) &table[i].code, cpos));
                opos++;
            }

            ipos++;
        }
        
        // apontar para o buffer dos dados comprimidos
        *compressed = comp;

        // retornar o numero de bytes nos dados comprimidos
        return ((opos - 1) / 8) + 1;
    }
}