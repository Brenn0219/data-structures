#ifndef DIRECTLS_H
#define DIRECTLS_H

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"

typedef struct Directory{
    char *name[257];
} Directory;

int directory(const char *path, Directory **dir);

#endif