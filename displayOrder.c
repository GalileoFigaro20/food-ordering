//
// Created by Ivan on 11/20/2019.
//

#include <stdio.h>
#include "defines.h"
#include "product.h"
#include <string.h>

void displayFood(char username[MAX_USERNAME] , product *food)
{
    printf("    This is your order : \n"
           "    ---Name---\n"
           "      %s\n"
           "    ---Food Items---\n"
           "      %s - %.2f$\n", username, food->name, food->price);
}

void displayDrinks(int drinkChoice, product *drink)
{
    //verifying if any beverage was bought
    if(drinkChoice != 4)
        printf("      %s - %.2f$\n", drink->name, drink->price);
}

void displayAdditionalOptions(char cutleryOption[MAX_FOOD_NAME], char additionalInfo[MAX_ADD_INFO])
{
    printf("    ---Cutlery---\n"
           "      %s\n", cutleryOption);

    if(strcmp(additionalInfo, "") != 0)
        printf("    ---Additional information---\n"
               "      %s\n", additionalInfo);
}

void displayTotalAmount(double totalAmount, product *food, product *drink)
{
    totalAmount = 0;
    totalAmount += food->price + drink->price;
    printf("    ---Payment amount---\n"
           "      %.2f$\n", totalAmount);
    printf("a) Confirm order.\n"
           "b) Go back.\n");
}


