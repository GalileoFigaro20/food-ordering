//
// Created by Ivan on 11/29/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "defines.h"

#include "login.h"

void readUsersFromFile(char line[MAX_LINE], FILE* database, User* v, int *noOfUsers)
{
    while(fgets(line, MAX_LINE, database))
    {
        char* temp = strtok(line, " ");
        strcpy(v[*noOfUsers].username, temp);
        temp = strtok(NULL, " ");
        strcpy(v[*noOfUsers].password, temp);
        int j = 0;
        while(temp[j] != '\n' && temp[j] != '\0')
        {
            j++;
        }
        v[*noOfUsers].password[j] = '\0';
        (*noOfUsers)++;
    }
}

void signingOption(int* incrementingChoice, int* loginChoice)
{
    printf(SIGN_IN_UP"\n"
                     "a)"SIGN_IN"\n"
                                "b)"SIGN_UP"\n");
    char c = getchar();
    getchar();
    *incrementingChoice = c - 'a' + 1;
    (*loginChoice)++;
}

void signingParsing(int* incrementingChoice, int* loginChoice, char username[MAX_USERNAME], char password[MAX_USERNAME])
{
    if(*incrementingChoice == 1)
    {
        printf(SIGNING_IN"\n");
    }else printf(SIGNING_UP"\n");
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    gets(password);
    (*loginChoice) += *incrementingChoice;
}

void searchUser(User* v, char *username, bool* userFound, int* userIndex, int noOfUsers)
{
    for(int i = 0; i < noOfUsers; i++)
    {
        if(strcmp(v[i].username, username) == 0)
        {
            *userFound = true;
            *userIndex = i;
        }
    }
}

void verifyPassword(User* v, char password[MAX_USERNAME], bool userFound, int userIndex, bool* loggedIn, int* loginChoice, int incrementingChoice)
{
    if(userFound == true)
    {
        if(strcmp(v[userIndex].password, password) == 0)
        {
            *loggedIn = true;
        }
    }else
    {
        printf(USER_NOT_FOUND);
        *loginChoice = 0;
    }

    if(*loggedIn == false && userFound == true)
    {
        printf(INCORRECT_PASSWORD);
        *loginChoice -= incrementingChoice;
    }
}

void verifyUsername(User* v, char username[MAX_USERNAME], int* loginChoice, int noOfUsers)
{
    for(int i = 0; i < noOfUsers; i++)
    {
        if(strcmp(username, v[i].username) == 0)
        {
            printf(DUPLICATE_USER);
            *loginChoice = 1;
        }
    }
}

void verifyPassLength(char password[MAX_USERNAME], int* loginChoice, bool* hasError)
{
    if(strlen(password) < 7)
    {
        printf(ERROR_PASSWORD_LONG);
        (*loginChoice)++;
        *hasError = true;
    }
}

void verifyPassContainUsername(char username[MAX_USERNAME], char password[MAX_USERNAME], int* loginChoice, bool* hasError)
{
    if(strstr(password, username) != NULL && *hasError == false)
    {
        printf(ERROR_PASSWORD_NOT_USERNAME);
        (*loginChoice)++;
        *hasError = true;
    }
}

void verifyPassSpecialChar(char password[MAX_USERNAME],int* loginChoice, bool* hasError)
{
    if(strchr(password, '.') == NULL && strchr(password, '_') == NULL && strchr(password, '!') == NULL && *hasError == false)
    {
        printf(ERROR_PASSWORD_SPECIAL_CHAR);
        (*loginChoice)++;
        *hasError = true;
    }
}

void verifyPassDigits(char password[MAX_USERNAME], int* loginChoice, bool* hasError)
{
    bool hasDigits = false;
    for(int i = 0; i < strlen(password); i++)
    {
        if(strchr(NUMBERS, password[i]))
            hasDigits = true;
    }
    if(hasDigits == false && *hasError == false)
    {
        printf(ERROR_PASSWORD_DIGITS);
        (*loginChoice)++;
        *hasError = true;
    }
}

void verifyPass(char password[MAX_USERNAME], char username[MAX_USERNAME], int* loginChoice, bool* hasError)
{

    if(*loginChoice != 1)
    {
        verifyPassLength(password, &(*loginChoice), &(*hasError));
        verifyPassContainUsername(username, password, &(*loginChoice), &(*hasError));
        verifyPassSpecialChar(password, &(*loginChoice), &(*hasError));
        verifyPassDigits(password, &(*loginChoice), &(*hasError));
    }
}

void addUser(User* v, char username[MAX_USERNAME], char password[MAX_USERNAME], bool* loggedIn, int* noOfUsers)
{
    strcpy(v[*noOfUsers].username, username);
    strcpy(v[*noOfUsers].password, password);
    (*noOfUsers)++;
    *loggedIn = true;
}

void getPassword(char password[MAX_USERNAME], int* loginChoice)
{
    printf(">");
    gets(password);
    (*loginChoice)--;
}

void Login(char username[MAX_USERNAME], char password[MAX_USERNAME], int *noOfUsers, User* v)
{
    int loginChoice = 0, incrementingChoice = 0;
    bool loggedIn = false;
    while(loggedIn == false)
    {
        switch(loginChoice)
        {
            case 0 :
            {
                signingOption(&incrementingChoice, &loginChoice);
                break;
            }

            case 1 :
            {
                signingParsing(&incrementingChoice, &loginChoice, username, password);
                break;
            }

                ///SIGN IN
            case 2 :
            {
                bool userFound = false;
                int userIndex = 0;
                searchUser(v, username, &userFound, &userIndex, *noOfUsers);
                verifyPassword(v, password, userFound, userIndex, &loggedIn, &loginChoice, incrementingChoice);
                break;
            }

                ///SIGN UP
            case 3 :
            {
                bool hasError = false;
                verifyUsername(v, username, &loginChoice, *noOfUsers);
                verifyPass(password, username, &loginChoice, &hasError);

                if(hasError == true || loginChoice != 3)
                    break;

                addUser(v, username, password, &loggedIn, &(*noOfUsers));
                break;
            }

            case 4 :
            {
                getPassword(password, &loginChoice);
                break;
            }

            default :
            {
                break;
            }
        }
    }
}

void writeUsers(User* v, FILE *database, int noOfUsers)
{
    for(int i = 0; i < noOfUsers; i++)
    {
        fprintf(database, "%s %s\n", v[i].username, v[i].password);
    }
}

void loginProcess(char username[MAX_USERNAME], char password[MAX_USERNAME])
{
    int noOfUsers = 0;
    char line[MAX_USERNAME];
    User* v = (User*)malloc(MAX_USERS* sizeof(User));

    FILE* database;
    database = fopen("E:\\UTCN- CTI- 2019\\Computer Programming\\Laboratory Projects\\food-ordering\\database.txt", "r");
    if(database == NULL)
    {
        printf("Database not found!\n");
    }
    readUsersFromFile(line, database,v , &noOfUsers);
    fclose(database);

    Login(username, password, &noOfUsers, v);

    database = fopen("E:\\UTCN- CTI- 2019\\Computer Programming\\Laboratory Projects\\food-ordering\\database.txt", "w");
    if(database == NULL)
    {
        printf("no database found!\n");
    }
    writeUsers(v, database, noOfUsers);
    fclose(database);
}