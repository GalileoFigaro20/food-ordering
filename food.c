//
// Created by Ivan on 12/21/2019.
//
#include "food.h"
#include <string.h>

void parseFoodName(food *f, int i, char* p)
{
    strcpy(f[i].name, p);
    f[i].name[strlen(p) - 4] = '\0';
}