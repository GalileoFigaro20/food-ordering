//
// Created by Ivan on 11/4/2019.
//

#include <stdio.h>
#include "defines.h"
#include <string.h>
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


void displayFoodPlusDrinks(char username[MAX_USERNAME] , char chosenFood[MAX_NAME], int drinkChoice, double chosenFoodPrice, char drink[MAX_NAME], double drinkPrice)
{
    printf("    This is your order : \n"
           "    ---Name---\n"
           "      %s\n"
           "    ---Food Items---\n"
           "      %s - %.2f$\n", username, chosenFood, chosenFoodPrice);

    //verifying if any beverage was bought
    if(drinkChoice != 4)
        printf("      %s - %.2f$\n", drink, drinkPrice);
}

void displayAdditionalOptions(char cutleryOption[MAX_NAME], char additionalInfo[MAX_ADD_INFO])
{
    printf("    ---Cutlery---\n"
           "      %s\n", cutleryOption);

    if(strcmp(additionalInfo, "") != 0)
        printf("    ---Additional information---\n"
               "      %s\n", additionalInfo);
}

void displayTotalAmount(double totalAmount, double chosenFoodPrice, double drinkPrice)
{
    totalAmount = 0;
    totalAmount += chosenFoodPrice + drinkPrice;
    printf("    ---Payment amount---\n"
           "      %.2f$\n", totalAmount);
    printf("a) Confirm order.\n"
           "b) Go back.\n");
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


