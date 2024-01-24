#ifndef COMPRESS_H
#define COMPRESS_H

#include "bitree.h"

/// @brief Definir uma estrutura para os nodos das arvores Huffu nman
typedef struct HuffNode {
    unsigned char symbol;
    int freq;
} HuffNode;

/// @brief Estrutura para as entradas nas tabelas de codigo Huffuman
typedef struct HuffCode {
    unsigned char used;
    unsigned short code;
    unsigned char size;
} HuffCode;

// Definir o nuemro de bits necessarios para as fichas membro de LZ77
#define LZ77_TYPE_BITS 1
#define LZ77_WINOFF_BITS 12
#define LZ77_BUFLEN_BITS 5
#define LZ77_NEXT_BITS 8


// Definir tamanho da janela e buffer de observacao para LZ77. Cada um deve ser inferior ou igual a 2 elevado a LZ77_WINOFF_BITS e LZ77_BUFLEN_BITS, rescpetivamente.
#define LZ77_WINDOW_SIZE 4096
#define LZ77_BUFFER_SIZE 32

// Define o numero de bits para as fichas de frases de LZ77
#define LZ77_PHRASE_BITS (LZ77_TYPE_BITS + LZ77_WINOFF_BITS + LZ77_NEXT_BITS + LZ77_BUFLEN_BITS)

#endif