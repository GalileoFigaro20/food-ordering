//
// Created by Ivan on 11/28/2019.
//

#ifndef FOOD_ORDERING_PARSEDATA_H
#define FOOD_ORDERING_PARSEDATA_H

#include <stdio.h>
#include "defines.h"
#include "product.h"
#include "food.h"
#include <stdbool.h>

int parseNumberOfProduct(bool foundFile, FILE* fin);
void parseLine(bool foundFile, FILE* fin, char line[MAX_LINE]);
void computeNumberOfSpecificFood(int* noOfSpecificFood, int i, char line[MAX_LINE]);
void parseFoodName(food *f, int i, char* p);
void parseAllSpecificData(int noOfFood, bool foundFile, FILE* fin, char *line, int* noOfSpecificFood, food *foods);


#endif //FOOD_ORDERING_PARSEDATA_H
