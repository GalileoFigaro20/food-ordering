//
// Created by Ivan on 11/4/2019.
//
#include <stdio.h>
#include "defines.h"

void displayOptions(char **food, int noOfFood)
{
    for(int i = 0; i < noOfFood; i++)
    {
        putchar('a' + i);
        printf(") %s \n", food[i]);
    }

    printf("%c) Go back\n>", 'a' + noOfFood);
}

void displaySpecificOptions(int noOfProducts, char **product, double prices[])
{
    for(int i = 0; i < noOfProducts; i++)
    {
        putchar('a' + i);
        printf(") %s - (%.2f$)\n", product[i] , prices[i]);
    }

    printf("%c) Go back.\n>", 'a' + noOfProducts);
}

