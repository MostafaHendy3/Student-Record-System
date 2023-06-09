#include "allmethods.h"
#include <stdlib.h>
#include "../Data/data.h"
#include "../Data/Stack.h"
#include "../System/System.h"
#include <string.h>
#include <stdio.h>

Stack *students;

void AddStudentRecord()
{
    Student st = readStudent();
    push(students, st);
}
void printStudent(Student st)
{
    printf("--------------------\n");
    printf("Name: %s\n", st.name);
    printf("ID: %d\n", st.id);
    printf("Age: %d\n", st.age);
    printf("Grade: %d\n", st.Grade);
    printf("Gender: %d\n", st.gender);
    printf("--------------------\n");
}
Student readStudent()
{
    Student st;
    printf("Enter Name\n");
    st.name = (char *)malloc(30 * sizeof(char));
    scanf(" %[^\n]", st.name);
    //fgets(st.name, 30 * sizeof(char), stdin);
    // fgets(st.name, 30 * sizeof(char), stdin);
    printf("Enter ID\n");
    scanf("%d", &(st.id));
    printf("Enter age\n");
    scanf("%d", &(st.age));
readGrade:
    printf("Enter Grade range between [0,100]\n");
    scanf("%d", &(st.Grade));
    if (st.Grade > 100 || st.Grade < 0)
    {
        goto readGrade;
    }
    printf("\
            Enter Gender\n\
            0-male\n\
            1-female\n");
    scanf("%d", &(st.gender));
    fflush(stdin);
    printf("Enter password: \n");
    // char *pass = (char *)malloc(strlen(ad->password) + 1);
    st.password = malloc(sizeof(char) * 4);
    scanf(" %s", st.password);
    return st;
}
void RemoveStudentRecord()
{
    printf("Enter ID: ");
    int id;
    scanf("%d", &id);
    Remove(students, id);
}
void ViewStudentRecord()
{
    printf("Enter ID: ");
    int id;
    scanf("%d", &id);
    printStudent(*(Search(students, id)));
}
void ViewAllRecords()
{
    StackTraverse(students, printStudent);
}
void EditAdminPassword()
{
    char *newPassword = (char *)malloc(4 * sizeof(char));
    printf("Enter New Password: ");
    scanf("%s", newPassword);
    Admin1.password = newPassword;
    printf("Password Changed\n");
    printf("New Password: %s\n", Admin1.password);
}
void EditStudentGrade()
{
    printf("Enter ID: ");
    int id;
    scanf("%d", &id);
    Student* st = Search(students, id);
    printf("Enter New Grade: ");
    scanf("%d", &(st->Grade));
}
void EditStudentPassword(Student *st)
{
    char *newPassword = (char *)malloc(4 * sizeof(char));
    printf("Enter New Password: ");
    scanf("%s", newPassword);
    st->password = newPassword;
    printf("Password Changed\n");
}
void EditStudentName(Student *st)
{
    char *newName = (char *)malloc(30 * sizeof(char));
    printf("Enter New Name: \n");
    scanf(" %[^\n]", newName);
    fflush(stdin);
    st->name = newName;
    printf("Name Changed\n");
}
void Admin()
{
    while (1)
    {
        printf("Welcome ,Admin \n\
                    1. Add student record\n\
                    2. Remove student record\n\
                    3. View student record\n\
                    4. View all records\n\
                    5. Edit admin password\n\
                    6. Edit student grade\n\
                    7. Exit\n\
                    ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            AddStudentRecord();
            break;
        case 2:
            RemoveStudentRecord();
            break;
        case 3:
            ViewStudentRecord();
            break;
        case 4:
            ViewAllRecords();
            break;
        case 5:
            EditAdminPassword();
            break;
        case 6:
            EditStudentGrade();
            break;
        case 7:
            printf("Exit\n");
            return;
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}
void User()
{
    while (1)
    {
        printf("Enter ID\n");
        int id;
        scanf("%d", &id);
        Student *st = (Student *)malloc(sizeof(Student));
        st = Search(students, id);
        printf("ID: %d\n", st->id);
        if (st->id == 0)
        {
            printf("Invalid ID\n");
            continue;
        }
        printf("Enter Password\n");
        printf("password: %s\n", st->password);
        char *pass = (char *)malloc(4 * sizeof(char));
        scanf("%s", pass);
        if (strcmp(pass, st->password) == 0)
        {
            printf("Welcome %s\n", st->name);
            while (1)
            {
                printf("Please, Choose the number for a certain action.\n"
                       "1- View your record \n\
           2- Edit your password \n\
           3- Edit your name \n\
           0- Exit\n");
                int choice;
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printStudent(*st);
                    break;
                case 2:
                    EditStudentPassword(st);
                    break;
                case 3:
                    EditStudentName(st);
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
            break;
        }
        else
        {
            printf("Invalid Password\n");
            continue;
        }
    }
    
}