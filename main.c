// this is the Entry point to program
#include "System/System.h"
#include <stdlib.h>
#include "AllMethods/allmethods.h"
#include "Data/data.h"
#include "Data/Stack.h"
#define classSize 10
struct admin Admin1;
extern Stack * students;

int main()
{
    students =(Stack *) malloc(classSize*sizeof(Student));
    CreateStack(students);

    Admin1.name = "Admin";
    Admin1.password = PassWord;
    ChooseControl();
}