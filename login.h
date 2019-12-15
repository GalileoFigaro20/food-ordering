//
// Created by Ivan on 11/29/2019.
//

#ifndef FOOD_ORDERING_LOGIN_H
#define FOOD_ORDERING_LOGIN_H

typedef struct{
    char username[255];
    char password[255];
}User;

void readUsersFromFile(char line[MAX_LINE], FILE* database, User* v, int key);
void signingOption(int* incrementingChoice, int* loginChoice);
void signingParsing(int* incrementingChoice, int* loginChoice, char username[MAX_USERNAME], char password[MAX_USERNAME]);
void searchUser(User* v, char *username, bool* userFound, int* userIndex, int noOfUsers);
void verifyPassword(User* v, char password[MAX_USERNAME], bool userFound, int userIndex, bool* loggedIn, int* loginChoice, int incrementingChoice);
void verifyUsername(User* v, char username[MAX_USERNAME], int* loginChoice, int noOfUsers);
void verifyPassLength(char password[MAX_USERNAME], int* loginChoice, bool* hasError);
void verifyPassContainUsername(char username[MAX_USERNAME], char password[MAX_USERNAME], int* loginChoice, bool* hasError);
void verifyPassSpecialChar(char password[MAX_USERNAME], int* loginChoice, bool* hasError);
void verifyPassDigits(char password[MAX_USERNAME], int* loginChoice, bool* hasError);
void verifyPass(char password[MAX_USERNAME], char username[MAX_USERNAME], int* loginChoice, bool* hasError);
void addUser(User* v, char username[MAX_USERNAME], char password[MAX_USERNAME], bool* loggedIn, int* noOfUsers);
void getPassword(char password[MAX_USERNAME], int* loginChoice);
void Login(char username[MAX_USERNAME], char password[MAX_USERNAME], int *noOfUsers, User* v);
void writeUsers(User* v, FILE *database, int noOfUsers, int key);
void loginProcess(char username[MAX_USERNAME], char password[MAX_USERNAME], User* v);

#endif //FOOD_ORDERING_LOGIN_H
