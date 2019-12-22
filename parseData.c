//
// Created by Ivan on 11/28/2019.
//
#include <stdio.h>
#include "defines.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "product.h"
#include "food.h"

int parseNumberOfProduct(bool foundFile, FILE* fin)
{
    int noOfProduct = 0;
    if(foundFile)
    {
        fscanf(fin, "%d", &noOfProduct);
        fgetc(fin);
    }else
    {
        scanf("%d", &noOfProduct);
        getchar();
    }
    return noOfProduct;
}

void parseLine(bool foundFile, FILE* fin, char line[MAX_LINE])
{
    if(foundFile)
    {
        fgets(line, MAX_LINE, fin);
    }else
    {
        gets(line);
    }
}

void computeNumberOfSpecificFood(int* noOfSpecificFood, int i, char line[MAX_LINE])
{
    noOfSpecificFood[i] = 0;
    for(int j = 0; j < strlen(line); j++)
    {
        if(line[j] == '(')
            noOfSpecificFood[i]++;
    }
}

void parseAllSpecificData(int noOfFood, bool foundFile, FILE* fin, char *line, int* noOfSpecificFood, food *foods)
{
    for(int i = 0; i < noOfFood; i++)
    {
        parseLine(foundFile, fin, line);
        computeNumberOfSpecificFood(noOfSpecificFood, i, line);

        foods[i].products = (product*)malloc(noOfSpecificFood[i]* sizeof(product));
        foods[i].name = (char*)malloc(MAX_FOOD_NAME* sizeof(char));

        char aux[255];
        strcpy(aux, line);
        char *p = strtok(line, "()");

        parseFoodName(foods, i, p);
        parseData(aux + strlen(p), foods[i].products, "()", p);
    }
}
