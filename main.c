#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "customer.h"
#include "displayOptions.h"
#include "getOrder.h"
#include "displayOrder.h"
#include "parseData.h"
#include "login.h"

int main(){
    ///Variables
    char username[40], password[20], **cutlery = (char**)malloc(2* sizeof(char*)), additionalInfo[MAX_ADD_INFO], line[255];
    cutlery[0] = "yes"; cutlery[1] = "no";
    double totalAmount = 0;
    bool finishedOrder = false, foundFile = true;
    int currentState = 0, choice = 0, foodChoice = 0, specificFoodChoice = 0;
    int drinkChoice = 0, cutleryChoice = 0, noOfFood = 0, noOfDrinks = 0;

    ///Open files
    FILE *fin;
    fin = fopen("E:\\UTCN- CTI- 2019\\Computer Programming\\Laboratory Projects\\food-ordering\\data.in.txt", "r");
    if(fin == NULL)
    {
        foundFile = false;
        printf(LOAD_DATA);
    }

    ///reading & allocating food
    char **food = (char**)malloc(noOfFood* sizeof(char*));
    char ***specificFood = (char***)malloc(noOfFood * sizeof(char**));
    double **specificFoodPrices = (double**)malloc(noOfFood * sizeof(double*));
    int *noOfSpecificFood = (int*)malloc(noOfFood * sizeof(int));
    noOfFood = parseNumberOfProduct(foundFile, fin);
    parseAllSpecificData(noOfFood, foundFile, fin, line, noOfSpecificFood, food, specificFood, specificFoodPrices);

    ///reading & allocating drinks
    noOfDrinks = parseNumberOfProduct(foundFile, fin);
    char *p = NULL;
    double *drinksPrices = (double*)malloc(noOfDrinks * sizeof(double));
    char **drinks = (char**)malloc(noOfDrinks * sizeof(char*));
    parseLine(foundFile, fin, line);
    parseData(line, drinks, drinksPrices, "(,)", p);

    fclose(fin);

    User* v = (User*)malloc(MAX_USERS* sizeof(User));

    printf("Welcome to Food Thingies!\n");
    while(finishedOrder == false)
    {
        switch(currentState)
        {
            case 0 :
            {
                loginProcess(username, password, v);
                currentState++;
                break;
            }
            case 1 :
            {
                printf("Please choose the food you feel like eating today :\n");
                displayOptions(food, noOfFood);
                getChoiceIndex(choice, noOfFood, &currentState, &foodChoice);
                break;
            }
            case 2 :
            {
                displaySpecificOptions(noOfSpecificFood[foodChoice], specificFood[foodChoice], specificFoodPrices[foodChoice]);
                getChoiceIndex(choice, noOfSpecificFood[foodChoice], &currentState, &specificFoodChoice);
                break;
            }
            case 3 :
            {
                displaySpecificOptions(noOfDrinks, drinks, drinksPrices);
                getChoiceIndex(choice, noOfDrinks, &currentState, &drinkChoice);
                break;
            }
            case 4 :
            {
                printf("Do you want cutlery? :\n");
                displayOptions(cutlery, 2);
                getChoiceIndex(choice, 2, &currentState, &cutleryChoice);
                break;
            }
            case 5 :
            {
                addInfo(&currentState, additionalInfo);
                break;
            }
            case 6 :
            {
                displayFood(username, specificFood[foodChoice][specificFoodChoice],specificFoodPrices[foodChoice][specificFoodChoice]);
                displayDrinks(drinkChoice, drinks[drinkChoice], drinksPrices[drinkChoice]);
                displayAdditionalOptions(cutlery[cutleryChoice], additionalInfo);
                displayTotalAmount(totalAmount, specificFoodPrices[foodChoice][specificFoodChoice], drinksPrices[drinkChoice]);
                getFinalChoice(choice, username, &currentState, &finishedOrder);
                break;
            }
        }
    }

    freeMemory(food, specificFood, specificFoodPrices, drinks, drinksPrices, noOfFood, noOfSpecificFood, noOfDrinks);
}