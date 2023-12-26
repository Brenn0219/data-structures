#ifndef PAGE_H
#define PAGE_H

#include "clist.h"

typedef struct Page {
    int number;
    int reference;
} Page;

/// @brief 
/// @param current 
/// @return 
int replace_page(CListElmt **current);

#endif