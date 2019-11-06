//
// Created by Ivan on 11/4/2019.
//

#ifndef FOOD_ORDERING_PRODUCTS_H
#define FOOD_ORDERING_PRODUCTS_H
#include "defines.h"

///Variables
int noOfFood = 3;
char food[][30] = {"Pizza", "Pasta", "Salad"};
int noOfSpecificFood[] = {3, 2, 4};
char specificFood[3][4][MAX_NAME] =
        {
                {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                {"Chicken Alfredo", "Mac&Cheese"},
                {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}

        };
double specificFoodPrices[3][4] =
        {
                {21, 23, 19, 0},
                {23, 21, 0, 0},
                {23, 22, 19, 21}
        };
int noOfDrinks = 5;
char drinks[][MAX_NAME] = {"Coca-Cola", "Fanta", "Lipton", "Water", "No thanks"};
double drinksPrices[MAX_PRICE] = {5, 5, 5, 4, 0};
char cutlery[][MAX_NAME] = {"yes", "no"};

///Functions
void displayOptions(char food[][MAX_NAME], int noOfFood);
void displaySpecificOptions(int noOfProducts, char product[][MAX_NAME], double prices[]);

#endif //FOOD_ORDERING_PRODUCTS_H
