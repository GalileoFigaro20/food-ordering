//
// Created by Ivan on 11/4/2019.
//

#ifndef FOOD_ORDERING_GETORDER_H
#define FOOD_ORDERING_GETORDER_H

///Functions
void getChoiceIndex(int choice, int noOfProducts, int *currentState, int *indexChoice);
void addInfo(int *currentState, char* additionalInfo);
void getFinalChoice(int choice, char username[MAX_USERNAME], int *currentState, bool *finishedOrder);
void freeMemory(char **food, char ***specificFood, double **specificFoodPrices, char **drinks, double *drinksPrices, int noOfFood, int *noOfSpecificFood);

#endif //FOOD_ORDERING_GETORDER_H
