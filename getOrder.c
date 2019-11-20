//
// Created by Ivan on 11/4/2019.
//

#include <stdio.h>
#include "defines.h"
#include <stdbool.h>

void getChoiceIndex(int choice, int noOfProducts, int *currentState, int *indexChoice)
{
    choice = getchar();
    ///consume new line
    getchar();
    if(choice == 'a' + noOfProducts)
    {
        (*currentState)--;
    }else
    {
        *indexChoice = choice - 'a';
        (*currentState)++;
    }
}

void addInfo(int *currentState, char* additionalInfo)
{
    printf("Any additional info?\n>");
    gets(additionalInfo);
    (*currentState)++;
}


void getFinalChoice(int choice, char username[MAX_USERNAME], int *currentState, bool *finishedOrder)
{
    choice = getchar();
    ///consume new line
    getchar();
    if(choice == 'b')
    {
        (*currentState) -= 2;
    }else
    {
        printf("Order confirmed! Thank you for buying from us, %s\n", username);
        (*finishedOrder) = true;
    }
}


