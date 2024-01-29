#include <sys/types.h>
#include <sys/socket.h>

#include "compress.h"

int send_comp(int s, const unsigned char *data, int size, int flags) {
    unsigned char *compressed;
    int size_comp;

    // comprimir dados
    if ((size_comp = huffman_compress(data, &compressed, size)) < 0)
        return -1;
    
    // enviar dados comprimidos precedidos de seu tamanho
    if (send(s, (char *) &size_comp, sizeof(int), flags) != sizeof(int))
        return -1;

    if (send(s, (char *) compressed, size_comp, flags) != size_comp)
        return -1;

    // liberar o buffer dos dados comprimidos
    free(compressed);

    return 0;
}

int recv_comp(int s, unsigned char **data, int *size, int flags) {
    unsigned char *compressed;
    int size_comp;

    // receber dados comprimidos precedidos de seu tamanho
    if (recv(s, (char *) &size_comp, sizeof(int), flags) != sizeof(int))
        return -1;

    if ((compressed = (unsigned char *) malloc(size_comp)) == NULL)
        return -1;

    if (recv(s, (char *) compressed, size_comp, flags) != size_comp) {
        free(compressed);
        return -1;
    }

    // descomprimir dados
    if ((*size = huffman_ucompress(compressed, data)) < 0)
        return -1;

    // liberar o buffer dos dados comprimidos
    free(compressed);

    return 0;
}