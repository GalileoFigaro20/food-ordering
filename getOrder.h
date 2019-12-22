//
// Created by Ivan on 11/4/2019.
//



#ifndef FOOD_ORDERING_GETORDER_H
#define FOOD_ORDERING_GETORDER_H
#include "food.h"

///Functions
void getChoiceIndex(int choice, int noOfProducts, int *currentState, int *indexChoice);
void addInfo(int *currentState, char* additionalInfo);
void getFinalChoice(int choice, char username[MAX_USERNAME], int *currentState, bool *finishedOrder);
void freeMemory(food* foods, product *drinks, int noOfFood, int *noOfSpecificFood, int noOfDrinks);

#endif //FOOD_ORDERING_GETORDER_H
