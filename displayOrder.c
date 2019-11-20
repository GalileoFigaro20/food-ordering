//
// Created by Ivan on 11/20/2019.
//

#include <stdio.h>
#include "defines.h"
#include <string.h>

void displayFood(char username[MAX_USERNAME] , char chosenFood[MAX_NAME], double chosenFoodPrice)
{
    printf("    This is your order : \n"
           "    ---Name---\n"
           "      %s\n"
           "    ---Food Items---\n"
           "      %s - %.2f$\n", username, chosenFood, chosenFoodPrice);
}

void displayDrinks(int drinkChoice, char drink[MAX_NAME], double drinkPrice)
{
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


