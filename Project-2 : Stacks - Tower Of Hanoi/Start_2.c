// By HyperHBR--Hardiksinh Rathod 
// Date--
// Program Name--

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int count_steps=0;

struct stack
{
    int size;
    int top;
    int *arr;
}A,B,C;

int isFull(struct stack *ptr) //Creating Function And Returning Value For Furthur Use
{
    if(ptr->top == (ptr->size)-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack *ptr) //Creating Function And Returning Value For Furthur Use
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
    if(isFull(ptr))
    {
        printf("---Stack Overflow---\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        return 0;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->arr[ptr->top] = 0;
        ptr->top--;
        return val;
    }
}

void Initializing_Tower_Of_Hanoi();
void run();
void Printing_Top_Position(struct stack *A,struct stack *B,struct stack *C);
void Printing_Middle_Position(struct stack *A,struct stack *B,struct stack *C);
void Printing_Bottom_Position(struct stack *A,struct stack *B,struct stack *C);
void Printing_Base();

int main()
{
    Initializing_Tower_Of_Hanoi();    
    run();
    if(count_steps == 7)
    {
        printf("\nCongratulations,\n");
        printf("You Took %d Steps(Minimun To Solve The Problem)",count_steps);
    }
    else
    {
        printf("\nCongratulations,\n");
        printf("You Took %d Steps.\n",count_steps);
        printf("But,You Can Complete This Problem In 7 Steps");
    }
    
    return 0;
}

void Initializing_Tower_Of_Hanoi()
{
    A.size=3;
    B.size=3;
    C.size=3;

    A.top = -1;
    B.top = -1;
    C.top = -1;
    
    A.arr = (int *)malloc(A.size*sizeof(int));
    B.arr = (int *)malloc(B.size*sizeof(int));
    C.arr = (int *)malloc(C.size*sizeof(int));

    push(&A,3);
    push(&A,2);
    push(&A,1);
}

void run()
{
    system("clear");
    char tower_start;
    char tower_end;
    Printing_Top_Position(&A,&B,&C);
    Printing_Middle_Position(&A,&B,&C);
    Printing_Bottom_Position(&A,&B,&C);
    Printing_Base();

    while(!isFull(&C))
    {
        printf("\nFrom Which Tower Would You Like To Move A Disk?(A/B/C): ");
        scanf(" %c",&tower_start);

        if(tower_start == 'A')
        {
            if(isEmpty(&A))
            {
                printf("\nInvalid Choice Since The Tower Is Empty\n");
                continue;
            }
            else
            {
                printf("\nTo Which Tower Would You Like To Move A Disk?(B/C): ");
                scanf(" %c",&tower_end);
                if(tower_end== 'B')
                {
                    if(B.arr[B.top] > A.arr[A.top] || B.top==-1)
                    {
                        B.top++;
                        B.arr[B.top] = pop(&A);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
                else if(tower_end=='C')
                {
                    if(C.arr[C.top] > A.arr[A.top] || C.top==-1)
                    {
                        C.top++;
                        C.arr[C.top] = pop(&A);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
            }
        }
        else if(tower_start == 'B')
        {
            if(isEmpty(&B))
            {
                printf("\nInvalid Choice Since The Tower Is Empty\n");
                continue;
            }
            else
            {
                printf("\nTo Which Tower Would You Like To Move A Disk?(A/C): ");
                scanf(" %c",&tower_end);
                if(tower_end=='A')
                {
                    if(A.arr[A.top] > B.arr[B.top] || A.top==-1)
                    {
                        A.top++;
                        A.arr[A.top] = pop(&B);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
                else if(tower_end=='C')
                {
                    if(C.arr[C.top] > B.arr[B.top] || C.top==-1)
                    {
                        C.top++;
                        C.arr[C.top] = pop(&B);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
            }
        }
        else if(tower_start == 'C')
        {
            if(isEmpty(&C))
            {
                printf("\nInvalid Choice Since The Tower Is Empty\n");
                continue;
            }
            else
            {
                printf("\nTo Which Tower Would You Like To Move A Disk?(A/B): ");
                scanf(" %c",&tower_end);
            }
                if(tower_end=='A')
                {
                    if(A.arr[A.top] > C.arr[C.top] || A.top==-1)
                    {
                        A.top++;
                        A.arr[A.top] = pop(&C);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
                else if(tower_end=='B')
                {
                    if(B.arr[B.top] > C.arr[C.top] || B.top==-1)
                    {
                        B.top++;
                        B.arr[B.top] = pop(&C);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
        }
        count_steps++;
    }
}

void Printing_Base()
{
    for(int d=0;d<3;d++)
    {
        printf("------");
        printf("\t");
    }
}

void Printing_Top_Position(struct stack *A,struct stack *B,struct stack *C)
{
    if(A->top>-1 && A->arr[2]!=0)
    {
        for(int i=0;i<3-A->arr[2];i++)
        {
            printf(" ");
        }
        for(int i=0;i<A->arr[2];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-A->arr[2];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }

    printf("  ");

    if(B->top>-1 && B->arr[2]!=0)
    {
        for(int i=0;i<3-B->arr[2];i++)
        {
            printf(" ");
        }
        for(int i=0;i<B->arr[2];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-B->arr[2];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }

    printf("  ");

    if(C->top>-1 && C->arr[2]!=0)
    {
        for(int i=0;i<3-C->arr[2];i++)
        {
            printf(" ");
        }
        for(int i=0;i<C->arr[2];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-C->arr[2];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }
    printf("\n");
}

void Printing_Middle_Position(struct stack *A,struct stack *B,struct stack *C)
{
    if(A->top>-1 && A->arr[1]!=0)
    {
        for(int i=0;i<3-A->arr[1];i++)
        {
            printf(" ");
        }
        for(int i=0;i<A->arr[1];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-A->arr[1];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }

    printf("  ");

    if(B->top>-1 && B->arr[1]!=0)
    {
        for(int i=0;i<3-B->arr[1];i++)
        {
            printf(" ");
        }
        for(int i=0;i<B->arr[1];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-B->arr[1];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }

    printf("  ");

    if(C->top>-1 && C->arr[1]!=0)
    {
        for(int i=0;i<3-C->arr[1];i++)
        {
            printf(" ");
        }
        for(int i=0;i<C->arr[1];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-C->arr[1];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }
    printf("\n");
}

void Printing_Bottom_Position(struct stack *A,struct stack *B,struct stack *C)
{
    if(A->top>-1 && A->arr[0]!=0)
    {
        for(int i=0;i<3-A->arr[0];i++)
        {
            printf(" ");
        }
        for(int i=0;i<A->arr[0];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-A->arr[0];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }

    printf("  ");

    if(B->top>-1 && B->arr[0]!=0)
    {
        for(int i=0;i<3-B->arr[0];i++)
        {
            printf(" ");
        }
        for(int i=0;i<B->arr[0];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-B->arr[0];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }

    printf("  ");

    if(C->top>-1 && C->arr[0]!=0)
    {
        for(int i=0;i<3-C->arr[0];i++)
        {
            printf(" ");
        }
        for(int i=0;i<C->arr[0];i++)
        {
            printf("00");
        }
        for(int i=0;i<3-C->arr[0];i++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("      ");
    }
    printf("\n");
}
