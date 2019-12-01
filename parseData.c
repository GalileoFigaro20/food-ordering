//
// Created by Ivan on 11/28/2019.
//
#include <stdio.h>
#include "defines.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void parseProductName(char **product, char *p, int index, int *stringIndex)
{
    product[index] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
    while(p[*stringIndex] != '-' || p[*stringIndex+1] != ' ')
    {
        product[index][*stringIndex] = p[*stringIndex];
        (*stringIndex)++;
    }
    product[index][*stringIndex - 1] = '\0';
}

void parseProductPrice(double* productPrices, char* p, int* index, int* stringIndex)
{
    double x = 0;
    while(p[*stringIndex] != '\0')
    {
        if(isdigit(p[*stringIndex]))
            x = x * 10 + (p[*stringIndex] - '0');
        (*stringIndex)++;
    }
    if(x > 100)
    {
        productPrices[*index] = x/100;
    }else productPrices[*index] = x;

    (*index)++;
}

void parseData(char line[MAX_LINE], char** productName, double* productPrices, char token[MAX_LINE], char* p)
{
    p = strtok(line, token);
    int j = 0;
    while(p != NULL)
    {
        if(strcmp(p, " ") != 0 && strcmp(p, "\n") != 0)
        {
            int k = 0;
            parseProductName(productName, p, j, &k);
            parseProductPrice(productPrices, p, &j, &k);
        }
        p = strtok(NULL, token);
    }
}

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

void parseFoodName(char** food, int i, char* p)
{
    strcpy(food[i], p);
    food[i][strlen(p) - 4] = '\0';
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

void allocateFoodMemory(char** food, int i, char*** specificFood, int* noOfSpecificFood, double** specificFoodPrices)
{
    food[i] = (char*)malloc(MAX_FOOD_NAME * sizeof(char));
    specificFood[i] = (char**)malloc(noOfSpecificFood[i] * sizeof(char*));
    specificFoodPrices[i] = (double*)malloc(noOfSpecificFood[i] * sizeof(double));
}

void parseAllSpecificData(int noOfFood, bool foundFile, FILE* fin, char *line, int* noOfSpecificFood, char** food, char*** specificFood, double** specificFoodPrices)
{
    for(int i = 0; i < noOfFood; i++)
    {
        parseLine(foundFile, fin, line);
        computeNumberOfSpecificFood(noOfSpecificFood, i, line);

        allocateFoodMemory(food, i, specificFood, noOfSpecificFood, specificFoodPrices);

        char aux[255];
        strcpy(aux, line);
        char *p = strtok(line, "()");

        parseFoodName(food, i, p);
        parseData(aux + strlen(p), specificFood[i], specificFoodPrices[i], "()", p);
    }
}
