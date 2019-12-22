//
// Created by Ivan on 11/20/2019.
//

#ifndef FOOD_ORDERING_DISPLAYORDER_H
#define FOOD_ORDERING_DISPLAYORDER_H
#include "defines.h"

void displayFood(char username[MAX_USERNAME], product *food);
void displayDrinks(int drinkChoice, product *drink);
void displayAdditionalOptions(char cutleryOption[MAX_FOOD_NAME], char additionalInfo[MAX_ADD_INFO]);
void displayTotalAmount(double totalAmount, product *food, product *drink);

#endif //FOOD_ORDERING_DISPLAYORDER_H
