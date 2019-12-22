//
// Created by Ivan on 11/4/2019.
//

#ifndef FOOD_ORDERING_DISPLAYOPTIONS_H
#define FOOD_ORDERING_DISPLAYOPTIONS_H
#include "defines.h"
#include "food.h"

///Functions
void displayOptions(food* foods, int noOfFood);
void displaySpecificOptions(int noOfProducts, product *products);
void displayCutleryOptions(char **cutlery, int noOfOptions);

#endif //FOOD_ORDERING_DISPLAYOPTIONS_H
