#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "displayOptions.h"
#include "getOrder.h"
#include "displayOrder.h"
#include "parseData.h"
#include "login.h"
#include "product.h"

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
    noOfFood = parseNumberOfProduct(foundFile, fin);
    food *foods = (food*)malloc(noOfFood* sizeof(food));
    int *noOfSpecificFood = (int*)malloc(noOfFood * sizeof(int));
    parseAllSpecificData(noOfFood, foundFile, fin, line, noOfSpecificFood, foods);

    ///reading & allocating drinks
    noOfDrinks = parseNumberOfProduct(foundFile, fin);
    char *p = NULL;
    product *drinks = (product*)malloc(noOfDrinks * sizeof(product));
    parseLine(foundFile, fin, line);
    parseData(line, drinks, "(,)", p);

    fclose(fin);

    User* v = (User*)malloc(MAX_USERS* sizeof(User));

    enum State{
        LOGIN_PROCESS, CHOOSE_FOOD, CHOOSE_SPECIFIC_FOOD, CHOOSE_DRINK, CHOOSE_CUTLERY, ADDITIONAL_INFO, DISPLAY_AND_SIGN
    };
    printf("Welcome to Food Thingies!\n");
    while(finishedOrder == false)
    {
        switch(currentState)
        {
            case LOGIN_PROCESS :
            {
                loginProcess(username, password, v);
                currentState++;
                break;
            }
            case CHOOSE_FOOD :
            {
                printf("Please choose the food you feel like eating today :\n");
                displayOptions(foods, noOfFood);
                getChoiceIndex(choice, noOfFood, &currentState, &foodChoice);
                break;
            }
            case CHOOSE_SPECIFIC_FOOD :
            {
                displaySpecificOptions(noOfSpecificFood[foodChoice], foods[foodChoice].products);
                getChoiceIndex(choice, noOfSpecificFood[foodChoice], &currentState, &specificFoodChoice);
                break;
            }
            case CHOOSE_DRINK :
            {
                displaySpecificOptions(noOfDrinks, drinks);
                getChoiceIndex(choice, noOfDrinks, &currentState, &drinkChoice);
                break;
            }
            case CHOOSE_CUTLERY :
            {
                printf("Do you want cutlery? :\n");
                displayCutleryOptions(cutlery, 2);
                getChoiceIndex(choice, 2, &currentState, &cutleryChoice);
                break;
            }
            case ADDITIONAL_INFO :
            {
                addInfo(&currentState, additionalInfo);
                break;
            }
            case DISPLAY_AND_SIGN :
            {
                displayFood(username, &foods[foodChoice].products[specificFoodChoice]);
                displayDrinks(drinkChoice, &drinks[drinkChoice]);
                displayAdditionalOptions(cutlery[cutleryChoice], additionalInfo);
                displayTotalAmount(totalAmount, &foods->products[foodChoice], &drinks[drinkChoice]);
                getFinalChoice(choice, username, &currentState, &finishedOrder);
                break;
            }
        }
    }

    freeMemory(foods, drinks, noOfFood, noOfSpecificFood, noOfDrinks);
}