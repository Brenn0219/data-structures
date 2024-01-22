#include "spell.h"

static int compare_str(const void *str1, const void *str2) {
    int retval;

    if ((retval = strcmp((const char *) str1, (const char *) str2)) > 0)
        return 1;
    else if (retval < 0)
        return -1;
    else 
        return 0;
}

int spell(char *dictionary, int size, char *word) {
    if (bsearch(dictionary, word, size, SPELL_SIZE, compare_str) >= 0)
        return -1;
    else 
        return 0;
}