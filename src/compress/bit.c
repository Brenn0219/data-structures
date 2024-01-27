#include "bit.h"

int bit_get(const unsigned char *bits, int pos) {
    unsigned char mask = 0x80;

    for (int i = 0; i < (pos % 8); i++)
        mask = mask >> 1;

    return ((mask & bits[(int) (pos / 8)]) == mask) ? 1 : 0;
}

void bit_set(unsigned char *bits, int pos, int state) {
    unsigned char mask = 0x80;

    for (int i = 0; i < (pos % 8); i++)
        mask = mask >> 1;

    if (state)
        bits[(int)(pos / 8)] = bits[(int)(pos / 8)] | mask;
    else    
        bits[(int)(pos / 8)] = bits[(int)(pos / 8)] & (~mask);
}

void bit_xor(const unsigned char *bits1, const unsigned char *bits2, unsigned char *bitsx, int size) {
    for (int i = 0; i < size; i++) {
        if (bit_get(bits1, i) != bit_get(bits2, i))
            bit_set(bitsx, i , 1);
        else 
            bit_set(bitsx, i , 0);
    }
}

void bit_rot_left(unsigned char *bits, int size, int count) {
    int fbit, lbit;
    
    if (size <= 0)
        return;
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < (size / 8); j++) {
            lbit = bit_get(&bits[j], 0);

            if (j == 0)
                fbit = lbit;
            else 
                bit_set(&bits[j - 1], 7, lbit);

            bits[j] = bits[j] << 1;
        }

        bit_set(bits, size - 1, fbit);
    }
}