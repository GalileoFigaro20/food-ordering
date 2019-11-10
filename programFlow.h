//
// Created by Ivan on 11/4/2019.
//

#ifndef FOOD_ORDERING_PROGRAMFLOW_H
#define FOOD_ORDERING_PROGRAMFLOW_H

///Functions
void getChoiceIndex(int choice, int noOfProducts, int *currentState, int *indexChoice);
void addInfo(int *currentState, char* additionalInfo);
void displayFoodPlusDrinks(char username[MAX_USERNAME] , char chosenFood[MAX_NAME], int drinkChoice, double chosenFoodPrice, char drink[MAX_NAME], double drinkPrice);
void displayAdditionalOptions(char cutleryOption[MAX_NAME], char additionalInfo[MAX_ADD_INFO]);
void displayTotalAmount(double totalAmount, double chosenFoodPrice, double drinkPrice);
void getFinalChoice(int choice, char username[MAX_USERNAME], int *currentState, bool *finishedOrder);

#endif //FOOD_ORDERING_PROGRAMFLOW_H
