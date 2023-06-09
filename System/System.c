#include "System.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Data/data.h"
#include "../Data/Stack.h"
#include "../AllMethods/allmethods.h"
#include <string.h>

int numverOfTry = 0;
void ChooseControl()
{
    while (1)
    {
        printf("Choose Control:\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("0. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            AdminControl();
            break;
        case 2:
            UserControl();
            break;
        case 0:
            printf("Exit\n");
            return;
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}
void AdminControl()
{
    printf("Admin Control\n");
    printf("Password: %s\n", Admin1.password);
    printf("Enter Password: ");
    char *EnteredPassword = (char *)malloc(4 * sizeof(char));
    scanf("%s", EnteredPassword);
    if (comparePassword(EnteredPassword))
    {
        numverOfTry = 0;
        printf("Correct Password\n");
        Admin();
    }
    else
    {
        printf("Wrong Password\n");
        numverOfTry++;
        printf("Remaining %d times\n", 3 - numverOfTry);
        if (numverOfTry == 3)
        {
            printf("You have tried 3 times\n");
            exit(0);
        }
        else
        {
            AdminControl();
        }
    }
}
int comparePassword(char *EnteredPassword)
{
    if (strcmp(EnteredPassword, Admin1.password) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void UserControl()
{
    printf("User Control\n");
    User();

}