// 55 - Snake Code
// 11 - Ladder Code

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define GAME_SIZE 5
#define DICE_SIZE 3
#define NO_OF_SNAKES 2
#define NO_OF_LADDERS 2

int Dice_Got;
int Current_Location=0;

struct Snakes
{
    int Location;
    int Size;
};

struct Snakes S_Array[NO_OF_SNAKES] =  {
                                            2,-1,
                                            6,-3
                                        };

struct Ladders
{
    int Location;
    int Size;
};

struct Ladders L_Array[NO_OF_LADDERS] = {
                                            4,4,
                                            5,2,
                                        };

struct Node
{
    int data;
    struct Node *prevNode;
    struct Node *nextNode;
    int jump_size;
};

struct Node *Create_Node()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 0;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    newNode->jump_size = 0;
    return newNode;
}

void Printing_The_Box(struct Node *arr[GAME_SIZE*GAME_SIZE]);
void Initialize_The_Game(struct  Node *head);
void delay(int Seconds); //For Running Game Gradually
void Printing_The_Instructions();
void Running_The_Game(struct Node *arr[GAME_SIZE*GAME_SIZE]);
void Change_Of_Players_Location(struct Node *arr[GAME_SIZE*GAME_SIZE],int Change);
void Condition_Check();

int main()
{  
    Condition_Check();
    struct Node *head = NULL;

    Initialize_The_Game(head);
    Printing_The_Instructions();
    Printing_The_Box(Box);
}

void Condition_Check()
{
    if(GAME_SIZE>10)
    {
        printf("\nGAME SIZE GREATER THAN 10 NOT ALLOWED.");
        exit(0);
    }
    if(DICE_SIZE>6)
    {
        printf("\nDICE SIZE GREATER THAN 6 NOT ALLOWED.");
        exit(0);
    }

    for(int i=0;i<NO_OF_SNAKES;i++)
    {
        if((-S_Array[i].Size) > S_Array[i].Location-1)
        {
            printf("\nInvalid Snake Size At %d",S_Array[i].Location);
            exit(0);
        }
        for(int j=0;j<NO_OF_LADDERS;j++)
        {
            if(S_Array[i].Location+S_Array[i].Size == L_Array[j].Location)
            {
                printf("\nInvalid Snake Size At %d,Since Its Tail Is At Ladder",S_Array[i].Location);
                exit(0);
            }
        }
        for(int k=0;k<NO_OF_SNAKES;k++)
        {
            if(S_Array[i].Location+S_Array[i].Size == S_Array[k].Location)
            {
                printf("\nInvalid Snake Size At %d,Since Its Tail Is At Another Snake",S_Array[i].Location);
                exit(0);
            }
        }
        for(int j=0;j<NO_OF_LADDERS;j++)
        {
            if(S_Array[i].Location == L_Array[j].Location)
            {
                printf("\nInvalid Location Allocated To Snake And Ladder Since They Both Start At %d",S_Array[i].Location);
                exit(0);
            }
        }
    }

    for(int i=0;i<NO_OF_LADDERS;i++)
    {
        if(L_Array[i].Size >(GAME_SIZE*GAME_SIZE)-L_Array[i].Location-1)
        {
            printf("\nInvalid Ladder Size At %d",L_Array[i].Location);
            exit(0);
        }
        for(int k=0;k<NO_OF_LADDERS;k++)
        {
            if(L_Array[i].Location+L_Array[i].Size == L_Array[k].Location)
            {
                printf("\nInvalid Ladder Size At %d,Since Its Top Is At Another Ladder",L_Array[i].Location);
                exit(0);
            }
        }
        for(int j=0;j<NO_OF_SNAKES;j++)
        {
            if(L_Array[i].Location+L_Array[i].Size == S_Array[j].Location)
            {
            printf("\nInvalid Ladder Size At %d,Since Its Top Is At Snake's Mouth",L_Array[i].Location);
            exit(0);
            }
        }
    }
}

void Printing_The_Box(struct Node *arr[GAME_SIZE*GAME_SIZE])
{
    system("clear");
    printf("\n");
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
                    if(arr[(i*GAME_SIZE)+j]->jump_size>-10)
                    {
                        printf("*  Snake(%d)  * ",arr[(i*GAME_SIZE)+j]->jump_size);
                    }
                    else if(arr[(i*GAME_SIZE)+j]->jump_size>-100)
                    {
                        printf("* Snake(%d) * ",arr[(i*GAME_SIZE)+j]->jump_size);
                    }
                }
                else if(arr[(i*GAME_SIZE)+j]->data==11)
                {
                    if(arr[(i*GAME_SIZE)+j]->jump_size<10)
                    {
                        printf("*  Ladder(%d)  * ",arr[(i*GAME_SIZE)+j]->jump_size);
                    }
                    else if(arr[(i*GAME_SIZE)+j]->jump_size<100)
                    {
                        printf("*  Ladder(%d) * ",arr[(i*GAME_SIZE)+j]->jump_size);
                    }
                }
                else if((i*GAME_SIZE)+j==0)
                {
                    printf("*    START    * ");
                }
                else if((i*GAME_SIZE)+j==GAME_SIZE*GAME_SIZE-1)
                {
                    printf("*     END     * ");
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
                printf("* %d  ",((i*GAME_SIZE)+j+1));
                }
                else if(((i*GAME_SIZE)+j+1)<100)
                {
                printf("* %d ",((i*GAME_SIZE)+j+1));
                }
                else
                {
                printf("* %d",((i*GAME_SIZE)+j+1));
                }
                if(((i*GAME_SIZE)+j+1) == GAME_SIZE*GAME_SIZE)
                {
                    printf("         * ");
                }
                else if(((i*GAME_SIZE)+j+1) % GAME_SIZE == 0)
                {
                    printf(" ^^^^    * ");
                }
                else
                {
                    printf(" --->    * ");
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
                    if(arr[(i*GAME_SIZE)+j]->jump_size>-10)
                    {
                        printf("*  Snake(%d)  * ",arr[(i*GAME_SIZE)+j]->jump_size);
                    }
                    else if(arr[(i*GAME_SIZE)+j]->jump_size>-100)
                    {
                        printf("*  Snake(%d) * ",arr[(i*GAME_SIZE)+j]->jump_size);
                    }
                }
                else if(arr[(i*GAME_SIZE)+j]->data==11)
                {
                    if(arr[(i*GAME_SIZE)+j]->jump_size<10)
                    {
                        printf("*  Ladder(%d)  * ",arr[(i*GAME_SIZE)+j]->jump_size);
                    }
                    else if(arr[(i*GAME_SIZE)+j]->jump_size<100)
                    {
                        printf("*  Ladder(%d) * ",arr[(i*GAME_SIZE)+j]->jump_size);
                    }
                }
                else if((i*GAME_SIZE)+j==0)
                {
                    printf("*    START    * ");
                }
                else if((i*GAME_SIZE)+j==GAME_SIZE*GAME_SIZE-1)
                {
                    printf("*     END     * ");
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
                printf("* %d  ",((i*GAME_SIZE)+j+1));
                }
                else if(((i*GAME_SIZE)+j+1)<100)
                {
                printf("* %d ",((i*GAME_SIZE)+j+1));
                }
                else
                {
                printf("* %d",((i*GAME_SIZE)+j+1));
                }

                if(((i*GAME_SIZE)+j+1) == GAME_SIZE*GAME_SIZE)
                {
                    printf("         * ");
                }
                else if(((i*GAME_SIZE)+j+1) % GAME_SIZE == 0)
                {
                    printf(" ^^^^    * ");
                }
                else
                {
                    printf(" <---    * ");
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

void Initialize_The_Game(struct Node *head)
{
    head = Create_Node();
    head->data = 1;
    
    for(int i=0;i<GAME_SIZE*GAME_SIZE;i++)
    {
        struct Node *newNode = Create_Node();
        if( i < (GAME_SIZE*GAME_SIZE)-1 )
        {
            if(head->nextNode == NULL)
            {
                newNode->prevNode = head;
                head->nextNode = newNode;
            }
            else
            {
                struct Node *tp = head;
                while(tp->nextNode != NULL)
                {
                    tp = tp->nextNode;
                }
                tp->nextNode = newNode;
                newNode->prevNode = tp;
            }
        }
    }

    for(int i=0;i<NO_OF_SNAKES;i++)
    {
        arr[S_Array[i].Location-1]->data = 55;
        arr[S_Array[i].Location-1]->jump_size = S_Array[i].Size;
    }

    for(int i=0;i<NO_OF_LADDERS;i++)
    {
        arr[L_Array[i].Location-1]->data = 11;
        arr[L_Array[i].Location-1]->jump_size = L_Array[i].Size;
    }

    for(int i=0;i<(GAME_SIZE*GAME_SIZE)-1;i++)
    {
        arr[i]->nextNode = arr[i+1];
    }
    for(int i=1;i<GAME_SIZE*GAME_SIZE;i++)
    {
        arr[i]->prevNode = arr[i-1];
    }

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
            "   1.The Dice Ranges From 1 To %d\n"
            "   2.Snake Is Indicated By Snake Word On Top Of Each Box(If Exist) And A Number Which Tell By What Size You Will Go Back\n"
            "   3.Ladder Is Indicated By Ladder Word On Top Of Each Box(If Exist) And A Number Which Tell By What Size You Will Up Back\n"
            "   4.Game Ends When Player Reaches %dth Box.\n",DICE_SIZE,GAME_SIZE*GAME_SIZE
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
            Dice_Got = rand()%DICE_SIZE+1;
            printf("You Got %d",Dice_Got);
            if(Current_Location + Dice_Got < GAME_SIZE*GAME_SIZE)
            {
                Change_Of_Players_Location(arr,Dice_Got);
                printf("\nUpdating The Game Graphics.\n");
                delay(2000);
                Printing_The_Box(arr);
            }
            else
            {
                delay(1000);
                system("clear");
                printf("\nYou Got More Than Required Please Try Again");
                printf("\nYour Current Locations Is %d.",Current_Location+1);
                printf("\nYou Need %d Or Less To Proceed.",GAME_SIZE*GAME_SIZE-Current_Location-1);
                Printing_The_Box(arr);
            }
        }
    }
    else
    {
        Printing_The_Box(arr);
    }
}

void Change_Of_Players_Location(struct Node *arr[GAME_SIZE*GAME_SIZE],int Change)
{
    struct Node *tp = arr[Current_Location];

    if(tp->data==1)
    {
        tp->data = 0;
    }

    if(Change > 0) 
    {
        for(int i=0;i<Change;i++)
        {
            tp += 1;
        }
        Current_Location += Change;
    }
    else if(Change < 0)
    {
        for(int i=0;i<(-Change);i++)
        {
            tp -= 1;
        }
        Current_Location -= (-Change);
    }

    if(tp->data == 11 && tp->data != 0 && tp->data != 1)
    {
        printf("\nLadder Encountered At %d",Current_Location+1);
        Change_Of_Players_Location(arr,tp->jump_size);

    }
    else if(tp->data == 55 && tp->data != 0 && tp->data != 1)
    {
        printf("\nSnake Encountered  At %d",Current_Location+1);
        Change_Of_Players_Location(arr,tp->jump_size);

    }
    else
    {
        tp->data = 1;
        printf("\nYou New Location Is %d",Current_Location+1);
    }
}
