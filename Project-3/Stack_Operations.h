// By HyperHBR--Hardiksinh Rathod 
// Date--
// Program Name--

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFullStack(struct stack *ptr) //Creating Function And Returning Value For Furthur Use
{
    if(ptr->top == (ptr->size)-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmptyStack(struct stack *ptr) //Creating Function And Returning Value For Furthur Use
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,int val)
{
    if(isFullStack(ptr))
    {
        printf("---Stack Overflow---\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack *ptr)
{
    if(isEmptyStack(ptr))
    {
        printf("---Stack Underflow---\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("%d Is Popped Out Of The Stack.\n",val);
    }
}

void peekStack(struct stack *ptr,int pos)
{
    if(pos <= 0)
    {
        printf("\nPlease Enter A Valid Position");
    }
    else if(pos>(ptr->top)+1)
    {
        printf("\nRange Out Of Bound");
    }
    else
    {
        printf("\nElement At Position %d Is %d.",pos,ptr->arr[ptr->top + 1 - pos]);
    }
}

void stackTop(struct stack *ptr)
{
    printf("\n-->Element Present At Top Is: %d ",ptr->arr[ptr->top]);
}

void stackBottom(struct stack *ptr)
{
    printf("\n-->Element Present At Bottom Is: %d ",ptr->arr[0]);
}

void traverseStack(struct stack *ptr)
{
    if(isEmptyStack(ptr))
    {
        printf("Stack Underflow");
    }
    else
    {
        for(int i=ptr->top ;i>=0; i--)
        {
            printf("\nThe Element At Index %d Is %d.",i,ptr->arr[i]);
        }

        for(int i=1;i<=(ptr->top)+1; i++)
        {
            printf("\nThe Element At Position %d Is %d.",i,ptr->arr[(ptr->top)-i+1]);
        }
    }
}
