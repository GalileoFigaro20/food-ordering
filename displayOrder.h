//
// Created by Ivan on 11/20/2019.
//

#ifndef FOOD_ORDERING_DISPLAYORDER_H
#define FOOD_ORDERING_DISPLAYORDER_H
#include "defines.h"

void displayFood(char username[MAX_USERNAME] , char chosenFood[MAX_NAME], double chosenFoodPrice);
void displayDrinks(int drinkChoice, char drink[MAX_NAME], double drinkPrice);
void displayAdditionalOptions(char cutleryOption[MAX_NAME], char additionalInfo[MAX_ADD_INFO]);
void displayTotalAmount(double totalAmount, double chosenFoodPrice, double drinkPrice);

#endif //FOOD_ORDERING_DISPLAYORDER_H
