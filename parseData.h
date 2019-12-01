//
// Created by Ivan on 11/28/2019.
//

#ifndef FOOD_ORDERING_PARSEDATA_H
#define FOOD_ORDERING_PARSEDATA_H

#include <stdio.h>
#include "defines.h"
#include <stdbool.h>

void parseProductName(char **product, char *p, int index, int *stringIndex);
void parseProductPrice(double* productPrices, char* p, int* index, int* stringIndex);
void parseData(char line[MAX_LINE], char** productName, double* productPrices, char token[MAX_LINE], char *p);
int parseNumberOfProduct(bool foundFile, FILE* fin);
void parseLine(bool foundFile, FILE* fin, char line[MAX_LINE]);
void computeNumberOfSpecificFood(int* noOfSpecificFood, int i, char line[MAX_LINE]);
void allocateFoodMemory(char** food, int i, char*** specificFood, int* noOfSpecificFood, double** specificFoodPrices);
void parseFoodName(char** food, int i, char* p);
void parseAllSpecificData(int noOfFood, bool foundFile, FILE* fin, char *line, int* noOfSpecificFood, char** food, char*** specificFood, double** specificFoodPrices);


#endif //FOOD_ORDERING_PARSEDATA_H
