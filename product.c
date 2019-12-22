//
// Created by Ivan on 12/21/2019.
//
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "defines.h"
#include "product.h"
#include <string.h>

void parseProductName(product *prod, char *p, int *stringIndex)
{
    prod->name = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
    while(p[*stringIndex] != '-' || p[*stringIndex+1] != ' ')
    {
        prod->name[*stringIndex] = p[*stringIndex];
        (*stringIndex)++;
    }
    prod->name[*stringIndex - 1] = '\0';
}

void parseProductPrice(product *prod, char* p, int* stringIndex)
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
        prod->price = x/100;
    }else prod->price = x;

}

void parseData(char line[MAX_LINE], product *products, char token[MAX_LINE], char* p)
{
    p = strtok(line, token);
    int j = 0;
    while(p != NULL)
    {
        if(strcmp(p, " ") != 0 && strcmp(p, "\n") != 0)
        {
            int k = 0;
            products[j].name = (char*)malloc(MAX_DRINK_NAME* sizeof(char));
            parseProductName(&products[j], p, &k);
            parseProductPrice(&products[j], p, &k);
            j++;
        }
        p = strtok(NULL, token);
    }
}

void displaySpecificOptions(int noOfProducts, product *products)
{
    for(int i = 0; i < noOfProducts; i++)
    {
        putchar('a' + i);
        printf(") %s - (%.2f$)\n", products[i].name , products[i].price);
    }

    printf("%c) Go back.\n>", 'a' + noOfProducts);
}



