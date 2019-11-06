//
// Created by Ivan on 11/4/2019.
//

#include <stdio.h>
#include "defines.h"

void inputCostumerData(char username[MAX_USERNAME], char password[MAX_USERNAME])
{
    printf("Please sign in to continue!\n"
           "---username---\n>");
    gets(username);
    printf("---password---\n>");
    gets(password);
}