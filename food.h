//
// Created by Ivan on 12/21/2019.
//

#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H
#include <stdlib.h>
#include "product.h"

typedef struct _food
{
    char* name;
    product* products;
}food;

void parseFoodName(food *f, int i, char* p);


#endif //FOOD_ORDERING_FOOD_H
