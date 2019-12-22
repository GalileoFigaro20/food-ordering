//
// Created by Ivan on 11/4/2019.
//
#include <stdio.h>
#include "product.h"
#include "food.h"

void displayOptions(food *foods, int noOfFood)
{
    for(int i = 0; i < noOfFood; i++)
    {
        putchar('a' + i);
        printf(") %s \n", foods[i].name);
    }

    printf("%c) Go back\n>", 'a' + noOfFood);
}

void displayCutleryOptions(char **cutlery, int noOfOptions)
{
    for(int i = 0; i < noOfOptions; i++)
    {
        putchar('a' + i);
        printf(") %s \n", cutlery[i]);
    }

    printf("%c) Go back\n>", 'a' + noOfOptions);
}
