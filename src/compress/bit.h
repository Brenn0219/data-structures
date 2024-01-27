#ifndef BIT_H
#define BIT_H

/// @brief Toma o estado do bit na posicao pos no buffer bits
/// @param bits buffer
/// @param pos posicao do bit
/// @return Estado do bit desejado: 1 ou 0
/// @complexity O(1)
int bit_get(const unsigned char *bits, int pos);

/// @brief Define o estado do bit na posicao pos no buffer bits para o valor especificado por state
/// @param bits buffer
/// @param pos posicao no buffer
/// @param state estado do bit
/// @complexity O(1) 
void bit_set(unsigned char *bits, int pos, int state);

/// @brief Computa o bitwize XOR (OR exclusivo)
/// @param bits1 buffer 1
/// @param bits2 buffer 2
/// @param bitsx retorna o valor do XOR do buffer1 com o buffer2
/// @param size quantidade dos bits
/// @complexity O(n), numero de bits em cada buffer
void bit_xor(const unsigned char *bits1, const unsigned char *bits2, unsigned char *bitsx, int size);

/// @brief Gira os bits do buffer
/// @param bits buffer
/// @param size tamanho do buffer
/// @param count 
/// @complexity O(n), numero de bits em cada buffer
void bit_rot_left(unsigned char *bits, int size, int count);

#endif