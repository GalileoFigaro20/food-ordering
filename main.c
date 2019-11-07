#include <stdio.h>
#include <stdbool.h>
#include "customer.h"
#include "products.h"
#include "programFlow.h"

int main() {
    char username[40], password[20], food[][30] = {"Pizza", "Pasta", "Salad"};
    int noOfFood = 3, noOfDrinks = 5, noOfSpecificFood[] = {3, 2, 4};
    char specificFood[3][4][MAX_NAME] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},{"Chicken Alfredo", "Mac&Cheese"},
                                         {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}};
    char drinks[][MAX_NAME] = {"Coca-Cola", "Fanta", "Lipton", "Water", "No thanks"}, cutlery[][MAX_NAME] = {"yes", "no"}, additionalInfo[MAX_ADD_INFO];
    double totalAmount = 0, drinksPrices[MAX_PRICE] = {5, 5, 5, 4, 0}, specificFoodPrices[3][4] = {{21, 23, 19, 0},{23, 21, 0, 0},{23, 22, 19, 21}};
    bool finishedOrder = false;
    int currentState = 0, choice, foodChoice, specificFoodChoice, drinkChoice, cutlerychoice;
    printf("Welcome to Food Thingies!\n");
    while(finishedOrder == false)
    {
        switch(currentState)
        {
            case 0 :
            {
                inputCostumerData(username, password);
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
                getChoiceIndex(choice, 2, &currentState, &cutlerychoice);
                break;
            }
            case 5 :
            {
                addInfo(&currentState, additionalInfo);
                break;
            }
            case 6 :
            {
                displayFoodPlusDrinks(username, specificFood[foodChoice][specificFoodChoice], drinkChoice, specificFoodPrices[foodChoice][specificFoodChoice],
                             drinks[drinkChoice], drinksPrices[drinkChoice]);
                displayAdditionalOptions(cutlery[cutlerychoice], additionalInfo);
                displayTotalAmount(totalAmount, specificFoodPrices[foodChoice][specificFoodChoice], drinksPrices[drinkChoice]);
                getFinalChoice(choice, username, &currentState, &finishedOrder);
                break;
            }
        }
    }
}