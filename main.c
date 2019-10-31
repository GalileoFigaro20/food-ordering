#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

    printf("Welcome to Food Thingies!\n");

    ///Variables for the program flow
    bool finishedOrder = false;
    int currentState = 0;

    ///Prefab variables
    int no_Of_foodTYPEs = 3;
    char foodTYPE[][30] = {"Pizza", "Pasta", "Salad"};
    int no_Of_specificFoodTYPE[] = {3, 2, 4};
    char specificFoodTYPE[3][4][30] =
            {
                    {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                    {"Chicken Alfredo", "Mac&Cheese"},
                    {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}

            };
    double specificFoodTYPE_prices[3][4] =
            {
                    {21, 23, 19},
                    {23, 21},
                    {23, 22, 19, 21}
            };
    int noOfDrinks = 5;
    char drinks[][30] = {"Coca-Cola", "Fanta", "Lipton", "Water", "No thanks"};
    double drinks_prices[5] = {5, 5, 5, 4, 0};
    char cutlery[][4] = {"yes", "no"};
    char additional_info[50];

    ///final choices variables
    int choice, foodTYPE_choice, specificFoodTYPETYPE_choice, specificFoodTYPE_quantity = 1, drink_choice, drink_choice_quantity = 1,  cutlery_choice;
    char c;

    ///total amount of the current order
    double total_amount = 0;

    ///Personal variables
    char Username[40], password[20];


    while(finishedOrder == false)
    {
        switch(currentState)
        {
            ///STATE #0 -> Signing in
            case 0 :
            {
                printf("Please sign in to continue!\n"
                       "---Username---\n"
                       ">");
                gets(Username);
                printf("---Password---\n"
                       ">");
                gets(password);

                currentState++;
                break;
            }

            ///State #1 -> Choosing the food type
            case 1 :
            {
                printf("Please choose the food you feel like eating today :\n");
                for(int i = 0; i < 3; i++)
                {
                    putchar('a' + i);
                    printf(") %s \n", foodTYPE[i]);
                }

                printf("%c) Go back\n>", 'a' + no_Of_foodTYPEs);
                choice = getchar();
                ///consume new line
                getchar();
                if(choice == 'a' + no_Of_foodTYPEs)
                {
                    currentState--;
                    break;
                }
                foodTYPE_choice = choice - 'a';
                currentState++;
                break;
            }


            ///STATE #2 -> Choosing the specific type of food
            case 2 :
            {
                for(int i = 0; i < no_Of_specificFoodTYPE[foodTYPE_choice]; i++)
                {
                    putchar('a' + i);
                    printf(") %s - (%.2f$)\n", specificFoodTYPE[foodTYPE_choice][i] ,specificFoodTYPE_prices[foodTYPE_choice][i]);
                }

                printf("%c) Go back.\n>", 'a' + no_Of_specificFoodTYPE[foodTYPE_choice]);
                choice = getchar();
                ///Consume new line
                getchar();

                if(choice == 'a' + no_Of_specificFoodTYPE[foodTYPE_choice])
                {
                    currentState--;
                    break;
                }
                specificFoodTYPETYPE_choice = choice - 'a';
                printf("Please introduce the quantity for the selected food\n>");
                scanf("%d", &specificFoodTYPE_quantity);
                while((c= getchar()) != '\n' && c != EOF);
                currentState++;
                break;
            }

            ///STATE #3 -> choosing the drink
            case 3 :
            {
                for(int i = 0; i < noOfDrinks; i++)
                {
                    putchar('a' + i);
                    printf(") %s (%.2f$)\n", drinks[i], drinks_prices[i]);
                }

                printf("%c) Go back.\n>", 'a' + noOfDrinks);
                choice = getchar();
                ///consume new line
                getchar();
                if(choice == 'a' + noOfDrinks)
                {
                    currentState--;
                    break;
                }
                drink_choice = choice - 'a';
                if(drink_choice < 4)
                {
                    printf("Please introduce the quantity you want for the selected drink :\n>");
                    scanf("%d", &drink_choice_quantity);
                    while((c= getchar()) != '\n' && c != EOF);
                }
                currentState++;
                break;
            }

            ///STATE #4 -> cutlery option
            case 4 :
            {
                printf("Do you want cutlery?\n");
                for(int i = 0; i < 2; i++)
                {
                    putchar('a' + i);
                    printf(") %s\n", cutlery[i]);
                }

                printf("c) Go back\n>");
                choice = getchar();
                getchar();
                if(choice == 'c')
                {
                    currentState--;
                    break;
                }

                cutlery_choice = choice - 'a';
                currentState++;
                break;
            }

            ///STATE #5 -> Additional information (ENTER if NONE)
            case 5 :
            {
                printf("Any additional info?\n>");
                gets(additional_info);
                currentState++;
                break;
            }

            ///STATE #6 -> Finishing order
            case 6 :
            {
                total_amount = 0;
                total_amount += specificFoodTYPE_prices[foodTYPE_choice][specificFoodTYPETYPE_choice]*specificFoodTYPE_quantity +
                        drink_choice_quantity*drinks_prices[drink_choice];
                printf("    This is your order : \n"
                       "    ---Name---\n"
                       "      %s\n"
                       "    ---Food Items---\n"
                       "     %d x %s - %.2f$\n", Username, specificFoodTYPE_quantity ,specificFoodTYPE[foodTYPE_choice][specificFoodTYPETYPE_choice],
                       specificFoodTYPE_prices[foodTYPE_choice][specificFoodTYPETYPE_choice]);

                //verifying if any beverage was bought
                if(drink_choice != 4)
                    printf("     %d x %s - %.2f$\n", drink_choice_quantity, drinks[drink_choice],drinks_prices[drink_choice]);

                printf("   ---Cutlery---\n"
                       "       %s\n"
                       "    ---Additional information---\n"
                       "      %s\n"
                       "    ---Payment amount---\n"
                       "         %.2f$\n",
                       cutlery[cutlery_choice], additional_info, total_amount);

                printf("a) Confirm order.\n"
                       "b) Go back.\n");
                choice = getchar();
                ///consume new line
                getchar();
                if(choice == 'b')
                {
                    currentState -= 2;
                    break;
                }

                printf("Order confirmed! Thank you for buying from us, %s\n", Username);
                finishedOrder = true;
                break;
            }
        }
    }
}