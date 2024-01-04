#ifndef LEX_H
#define LEX_H

#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "chtbl.h"
#include "symbol.h"

typedef enum Token {lexit, error, digit, other} Token;

Token lex(const char *istream, CHTbl *symtbl);

#endif