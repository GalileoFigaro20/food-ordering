//
// Created by Ivan on 11/4/2019.
//

#ifndef FOOD_ORDERING_PROGRAMFLOW_H
#define FOOD_ORDERING_PROGRAMFLOW_H

///Variables
char additionalInfo[MAX_ADD_INFO];
double totalAmount = 0;
bool finishedOrder = false;
int currentState = 0;
int choice, foodChoice, specificFoodChoice, drinkChoice, cutlerychoice;

///Functions
void getIndex(int choice, int noOfProducts, int *currentState, int *indexChoice);
void addInfo(int *currentState, char* additionalInfo);
void displayOrder(char username[MAX_USERNAME] , char chosenFood[MAX_NAME], int drinkChoice, double chosenFoodPrice, char drink[MAX_NAME], double drinkPrice,
                  char cutleryOption[MAX_NAME], char additionalInfo[MAX_ADD_INFO], double totalAmount);
void getFinalChoice(int choice, char username[MAX_USERNAME], int *currentState, bool *finishedOrder);

#endif //FOOD_ORDERING_PROGRAMFLOW_H
