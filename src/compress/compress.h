#ifndef COMPRESS_H
#define COMPRESS_H

#include "bitree.h"

/// @brief Definir uma estrutura para os nodos das arvores Huffuman
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

/// @brief Utiliza a codificacao Huffman para comprimir um buffer de dados especificados por original, que contem os bytes size
/// @param original buffer de dados
/// @param compressed dados comprimidos
/// @param size tamanho dos bytes
/// @return numero de bytes nos dados comprimidos se a compressao for bem sucedida, do contrario -1
/// @complexity O(n) 
int huffman_compress(const unsigned char *original, unsigned char **compressed, int size);

/// @brief Utiliza a descodificacao Huffman para descomprimir um buffer de dados especificados por compressed, que contem os bytes size
/// @param original buffer de dados originais
/// @param compressed dados comprimidos
/// @param size tamanho dos bytes
/// @return numero de bytes nos dados descomprimidos se a descompressao for bem sucedida, do contrario -1
/// @complexity O(n) 
int huffman_ucompress(const unsigned char *compressed, unsigned char **original);

#endif