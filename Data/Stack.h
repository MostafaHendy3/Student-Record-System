#ifndef Stack_H
#define Stack_H

#include "data.h"
#define StackEntry Student
#define MAX_STACK_SIZE 4

typedef struct stackNode
{
   StackEntry entry;
   struct stackNode * next;
}StackNode;

typedef struct stack{
   int size;
   StackNode * top;
}Stack;

void CreateStack(Stack *);
int StackSize(Stack *);
void ClearStack(Stack *);

void push(Stack *,StackEntry );
StackEntry pop(Stack *);

int StackFull();
int StackEmpty(Stack *);
StackEntry peek(Stack *);

void StackTraverse(Stack *,void(*pf)(StackEntry));
StackEntry * Search (Stack *ps,int id);
void Remove (Stack *ps,int id);
//StackSum of element
StackEntry StackSum(Stack *);
#endif