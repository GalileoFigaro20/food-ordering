#include <stdio.h>
#include <stdbool.h>
#include "customer.h"
#include "products.h"
#include "programFlow.h"

int main() {

    printf("Welcome to Food Thingies!\n");
    while(finishedOrder == false)
    {
        switch(currentState)
        {
            ///STATE #0 -> Signing in
            case 0 :
            {
                inputCostumerData(username, password);
                currentState++;
                break;
            }

                ///State #1 -> Choosing the food type
            case 1 :
            {
                printf("Please choose the food you feel like eating today :\n");
                displayOptions(food, noOfFood);
                getIndex(choice, noOfFood, &currentState, &foodChoice);
                break;
            }


                ///STATE #2 -> Choosing the specific type of food
            case 2 :
            {
                displaySpecificOptions(noOfSpecificFood[foodChoice], specificFood[foodChoice], specificFoodPrices[foodChoice]);
                getIndex(choice, noOfSpecificFood[foodChoice], &currentState, &specificFoodChoice);
                break;
            }

                ///STATE #3 -> choosing the drink
            case 3 :
            {
                displaySpecificOptions(noOfDrinks, drinks, drinksPrices);
                getIndex(choice, noOfDrinks, &currentState, &drinkChoice);
                break;
            }

                ///STATE #4 -> cutlery option
            case 4 :
            {
                printf("Do you want cutlery? :\n");
                displayOptions(cutlery, 2);
                getIndex(choice, 2, &currentState, &cutlerychoice);
                break;
            }

                ///STATE #5 -> Additional information (ENTER if NONE)
            case 5 :
            {
                addInfo(&currentState, additionalInfo);
                break;
            }

                ///STATE #6 -> Finishing order
            case 6 :
            {
                displayOrder(username, specificFood[foodChoice][specificFoodChoice], drinkChoice, specificFoodPrices[foodChoice][specificFoodChoice],
                             drinks[drinkChoice], drinksPrices[drinkChoice], cutlery[cutlerychoice], additionalInfo, totalAmount);
                getFinalChoice(choice, username, &currentState, &finishedOrder);
                break;
            }
        }
    }
}