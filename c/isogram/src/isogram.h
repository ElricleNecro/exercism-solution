#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <ctype.h>
#include <string.h>
#include <stdbool.h>

static const int OFFSET = 'a' - 'A';

bool is_isogram(const char phrase[]);

#endif