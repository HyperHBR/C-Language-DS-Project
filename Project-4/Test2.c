// 55 - Snake Code
// 11 - Ladder Code

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define GAME_SIZE 4
#define DICE_SIZE 3

int Dice_Got;
int Current_Location=0;

struct Node
{
    int data;
    struct Node *prevNode;
    struct Node *nextNode;
};

struct Node *Create_Node()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 0;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    return newNode;
}

void Printing_The_Box(struct Node *arr[GAME_SIZE*GAME_SIZE]);
void Initialize_The_Game(struct  Node *arr[]);
void delay(int Seconds); //For Running Game Gradually
void Printing_The_Instructions();
void Running_The_Game(struct Node *arr[GAME_SIZE*GAME_SIZE]);
void Change_Of_Players_Location(struct Node *arr[GAME_SIZE*GAME_SIZE],int Change);
void Ladder_Encountered(struct Node *arr[GAME_SIZE*GAME_SIZE],struct Node *tp);
void Snake_Encountered(struct Node *arr[GAME_SIZE*GAME_SIZE],struct Node *tp);

int main()
{  
    struct Node *arr[GAME_SIZE*GAME_SIZE];
    for(int i=0;i<GAME_SIZE*GAME_SIZE;i++)
    {
        arr[i] = Create_Node();
    }
    Initialize_The_Game(arr);
    Printing_The_Instructions();
    Printing_The_Box(arr);
}

void Printing_The_Box(struct Node *arr[GAME_SIZE*GAME_SIZE])
{
    system("clear");
    for(int i=GAME_SIZE-1;i>=0;i--)
    {
        for(int k=0;k<GAME_SIZE;k++)
        {
            printf("* * * * * * * * ");
        }
        printf("\n");
        if(i%2==0)
        {
            for(int j=0;j<GAME_SIZE;j++)
            {
                if(arr[(i*GAME_SIZE)+j]->data==55)
                {
                    printf("*  Snake (3)  * ");
                }
                else if(arr[(i*GAME_SIZE)+j]->data==11)
                {
                    printf("* Ladder (2)  * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<GAME_SIZE;j++)
            {
                if(arr[(i*GAME_SIZE)+j]->data == 1)
                {
                    printf("*     ###     * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<GAME_SIZE;j++)
            {
                if(arr[(i*GAME_SIZE)+j]->data == 1)
                {
                    printf("*      #      * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<GAME_SIZE;j++)
            {
                if(((i*GAME_SIZE)+j+1)<10)
                {
                printf("* %d           * ",((i*GAME_SIZE)+j+1));
                }
                else if(((i*GAME_SIZE)+j+1)<100)
                {
                printf("* %d          * ",((i*GAME_SIZE)+j+1));
                }
            }
            printf("\n");
        }
        else
        {
            for(int j=GAME_SIZE-1;j>=0;j--)
            {
                if(arr[(i*GAME_SIZE)+j]->data==55)
                {
                    printf("*  Snake (3)  * ");
                }
                else if(arr[(i*GAME_SIZE)+j]->data==11)
                {
                    printf("* Ladder (2)  * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=GAME_SIZE-1;j>=0;j--)
            {
                if(arr[(i*GAME_SIZE)+j]->data == 1)
                {
                    printf("*     ###     * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=GAME_SIZE-1;j>=0;j--)
            {
                if(arr[(i*GAME_SIZE)+j]->data == 1)
                {
                    printf("*      #      * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=GAME_SIZE-1;j>=0;j--)
            {
                if(((i*GAME_SIZE)+j+1)<10)
                {
                    printf("* %d           * ",((i*GAME_SIZE)+j+1));
                }
                else if(((i*GAME_SIZE)+j+1)<100)
                {
                    printf("* %d          * ",((i*GAME_SIZE)+j+1));
                }
            }
            printf("\n");
        }
    }
    for(int k=0;k<GAME_SIZE;k++)
        {
            printf("* * * * * * * * ");
        }
    printf("\n");
    if(arr[(GAME_SIZE*GAME_SIZE)-1]->data != 1)
    {
        Running_The_Game(arr);
    }
    else
    {
        printf("\n\n$$$$Congratulations$$$$");
    }
}

void Initialize_The_Game(struct  Node *arr[])
{
    for(int i=0;i<GAME_SIZE*GAME_SIZE;i++)
    {
        if(i==3 || i==7)
        {
            arr[i]->data = 55;
        }
        else if(i==5)
        {
            arr[i]->data = 11;
        }
        else
        {
            arr[i]->data = 0;
        }
    }

    for(int i=0;i<(GAME_SIZE*GAME_SIZE)-1;i++)
    {
        arr[i]->nextNode = arr[i+1];
    }
    for(int i=1;i<GAME_SIZE*GAME_SIZE;i++)
    {
        arr[i]->prevNode = arr[i-1];
    }

    arr[0]->data = 1;
    arr[0]->prevNode = NULL;
    arr[(GAME_SIZE*GAME_SIZE)-1]->nextNode = NULL;
}

void delay(int Seconds) //For Running Game Gradually
{
    // Converting Time Into Milli_Seconds
    int M_Seconds = 1000 * Seconds;

    // Storing Start Time
    clock_t Start_Time = clock();

    // Looping Till Delayed Time Is Achieved
    while (clock() < Start_Time + M_Seconds)
        ;
}

void Printing_The_Instructions()
{
    system("clear");
    char choice;
    printf("--------Welcome To The Snake And Ladder Game--------\n");
    printf( "\nHere Are The Instructions For The Game: \n\n"
            "   1.The Dice Ranges From 1 To 3\n"
            "   2.Snake Is Indicated By Snake Word On Top Of Each Box(If Exist) And A Number Which Tell By What Size You Will Go Back\n"
            "   3.Ladder Is Indicated By Ladder Word On Top Of Each Box(If Exist) And A Number Which Tell By What Size You Will Up Back\n"
            "   4.Game Ends When Player Reaches %dth Box.\n",GAME_SIZE*GAME_SIZE
            );

    printf("\nDo U Want To Start The Game?(Y): ");
    scanf(" %c",&choice);

    if(!(choice =='Y' || choice =='y'))
    {
        exit(0);
    }
}

void Running_The_Game(struct Node *arr[GAME_SIZE*GAME_SIZE])
{
    if(arr[(GAME_SIZE*GAME_SIZE)-1]->data != 1)
    {
        char choice;

        printf("\nPress R To Roll A Dice(R): ");
        scanf(" %c",&choice);

        if(!(choice =='R' || choice =='r'))
        {
            printf("Invalid Choice!!!\n");
            Running_The_Game(arr);
        }
        else
        {
            printf("-->Rolling A Dice\n");
            delay(2000);
            Dice_Got = rand()%3+1;
            printf("You Got %d",Dice_Got);
            if(Current_Location + Dice_Got < GAME_SIZE*GAME_SIZE)
            {
                Change_Of_Players_Location(arr,Dice_Got);
                printf("\nUpdating The Game Graphics.\n");
                delay(1000);
                Printing_The_Box(arr);
            }
            else
            {
                delay(1000);
                system("clear");
                printf("\nYou Got More Than Required Please Try Again");
                printf("\nYour Current Locations Is %d.",Current_Location+1);
                printf("\nYou Need %d Or Less To Proceed.",GAME_SIZE*GAME_SIZE-Current_Location-1);
                Running_The_Game(arr);
            }
        }
    }
    else
    {
        Printing_The_Box(arr);
    }
}

void Change_Of_Players_Location(struct Node *arr[GAME_SIZE*GAME_SIZE],int Change) //This Is Not Working
{
    int j=0;
    struct Node *tp=arr[j];
    struct Node *Current_Location_Data = arr[Current_Location];
    for(int i=0;i<Current_Location+Change;i++)
    {
        tp = arr[i+1];
    }

    if(tp->data == 11)
    {
        printf("\nLadder Encountered");
        Ladder_Encountered(arr,tp);
    }
    else if(tp->data == 55)
    {
        printf("\nSnake Encountered");
        Snake_Encountered(arr,tp);
    }
    else
    {
    tp->data = 1;
    }

    arr[Current_Location]->data = 0;
    Current_Location += Change;
    printf("\nYou New Location Is %d",Current_Location+1);
}

void Ladder_Encountered(struct Node *arr[GAME_SIZE*GAME_SIZE],struct Node *tp)
{
    for(int i=0;i<2;i++)
    {
        tp = arr[i+1];
    }
    Current_Location += 2;
}

void Snake_Encountered(struct Node *arr[GAME_SIZE*GAME_SIZE],struct Node *tp)
{
    for(int i=0;i<3;i++)
    {
        tp = arr[i-1];
    }
    Current_Location -= 3;
}