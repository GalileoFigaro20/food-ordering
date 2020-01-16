//
// Created by Ivan on 12/21/2019.
//

#ifndef FOOD_ORDERING_PRODUCT_H
#define FOOD_ORDERING_PRODUCT_H
#include "defines.h"

typedef struct _product{
    char* name;
    double price;
}product;

void parseData(char line[MAX_LINE], product *products, char token[MAX_LINE], char* p);
void displaySpecificOptions(int noOfProducts, product *products);

#endif //FOOD_ORDERING_PRODUCT_H
