//
// Created by Ivan on 11/4/2019.
//

#include <stdlib.h>
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

void freeMemory(char **food, char ***specificFood, double **specificFoodPrices, char **drinks, double *drinksPrices, int noOfFood, int *noOfSpecificFood, int noOfDrinks)
{
    for(int i = 0 ; i < noOfFood; i++)
    {
        for(int j = 0; j < noOfSpecificFood[i]; j++)
        {
            free(specificFood[i][j]);
        }
        free(specificFoodPrices[i]);
        free(food[i]);
        free(specificFood[i]);
    }

    for(int i = 0; i < noOfDrinks; i++)
    {
        free(drinks[i]);
    }
    free(specificFood);
    free(noOfSpecificFood);
    free(specificFoodPrices);
    free(food);
    free(drinks);
    free(drinksPrices);
}


