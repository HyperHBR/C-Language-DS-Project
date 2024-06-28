// 55 - Snake Code
// 11 - Ladder Code

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int Dice_Got;
int Current_Location=0;

struct Node
{
    int data;
    struct Node *prevNode;
    struct Node *nextNode;
};

struct Node *head,*second,*third,*fourth,*fifth,*sixth,*seventh,*eighth,*ninth;

void linkedListTraversal(struct Node *ptr)
{
    system("clear");
    while(ptr->nextNode != NULL) //From 1st To Last
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->nextNode;
    }
    printf("Element: %d\n",ptr->data);
}

struct Node *InsertAtStart(struct Node *head)
{
    int val;
    printf("What Value Do You Want To Enter At The Start: ");
    scanf("%d",&val);
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    new_node->data = val;
    new_node->nextNode = head;
    new_node->prevNode = NULL;
    head->prevNode = new_node;
    head = new_node;
    return head;
}

struct Node *InsertAtEnd(struct Node *head)
{
    int val;
    printf("What Value Do You Want To Enter At The Start: ");
    scanf("%d",&val);
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tp;
    while(tp->nextNode!=NULL)
    {
        tp = tp->nextNode;
    }
    new_node->data = val;
    tp->nextNode = new_node;
    new_node->prevNode = tp;
    new_node->nextNode = NULL;
    return head;
}

struct Node *InsertAtAfter(struct Node *head)
{
    int key;
    printf("\nEnter After What Value Do U Want TO Insert The Element: ");
    scanf("%d",&key);
    struct Node *tp = head;
    while(tp->data != key || tp->nextNode !=NULL)
    {
        tp = tp->nextNode;
    }
    if(tp->nextNode != NULL)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        struct Node *temp = tp->nextNode;
        int val;
        printf("What Value Do You Want To Enter At The Start: ");
        scanf("%d",&val);
        new_node->data = val;
        new_node->prevNode = tp;
        new_node->nextNode = temp;
        tp->nextNode = new_node;
        temp->prevNode =new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

struct Node *DeleteAtStart(struct Node *head)
{
    struct Node *temp = head;

    head = head->nextNode;
    head->prevNode = NULL;
    free(head);
    return head;
}

struct Node *DeleteAtEnd(struct Node *head)
{
    struct Node *tp = head;
    struct Node *temp;

    while((tp->nextNode)->nextNode != NULL)
    {
        tp=tp->nextNode;
    }
    temp = tp->nextNode;
    tp->nextNode = NULL;
    free(temp);

    return head;
}

struct Node *DeleteAfter(struct Node *head)
{
    int key;
    printf("\nEnter After What Value Do U Want To Delete The Element: ");
    scanf("%d",&key);
    struct Node *tp = head;
    while(tp->data != key || tp->nextNode !=NULL)
    {
        tp = tp->nextNode;
    }
    if(tp->nextNode !=NULL)
    {
        struct Node *temp;
        temp = tp->nextNode;
        tp->nextNode = temp->nextNode;
        (temp->nextNode)->prevNode = tp;
        free(temp);
        return head;
    }
    else
    {
        return NULL;
    }
}

void Printing_The_Box(struct Node *arr[9]);
void Initialize_The_Game(struct  Node *arr[]);
void delay(int Seconds); //For Running Game Gradually
void Printing_The_Instructions();
void Running_The_Game(struct Node *arr[9]);
void Change_Of_Players_Location(struct Node *arr[9],int Change);
void Ladder_Encountered(struct Node *arr[9],struct Node *tp);
void Snake_Encountered(struct Node *arr[9],struct Node *tp);

int main()
{  
    struct Node *arr[9] = {head,second,third,fourth,fifth,sixth,seventh,eighth,ninth};
    Initialize_The_Game(arr);
    Printing_The_Instructions();
    Printing_The_Box(arr);
}

void Printing_The_Box(struct Node *arr[9])
{
    system("clear");
    for(int i=3-1;i>=0;i--)
    {
        printf("* * * * * * * * * * * * * * * * * * * * * * * * \n");
        if(i%2==0)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[(i*3)+j]->data==55)
                {
                    printf("*  Snake (3)  * ");
                }
                else if(arr[(i*3)+j]->data==11)
                {
                    printf("* Ladder (2)  * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<3;j++)
            {
                if(arr[(i*3)+j]->data == 1)
                {
                    printf("*     ###     * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<3;j++)
            {
                if(arr[(i*3)+j]->data == 1)
                {
                    printf("*      #      * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=0;j<3;j++)
            {
                printf("* %d           * ",((i*3)+j+1));
            }
            printf("\n");
        }
        else
        {
            for(int j=3-1;j>=0;j--)
            {
                if(arr[(i*3)+j]->data==55)
                {
                    printf("*  Snake (3)  * ");
                }
                else if(arr[(i*3)+j]->data==11)
                {
                    printf("* Ladder (2)  * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=3-1;j>=0;j--)
            {
                if(arr[(i*3)+j]->data == 1)
                {
                    printf("*     ###     * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=3-1;j>=0;j--)
            {
                if(arr[(i*3)+j]->data == 1)
                {
                    printf("*      #      * ");
                }
                else
                {
                    printf("*             * ");
                }
            }
            printf("\n");
            for(int j=3-1;j>=0;j--)
            {
                printf("* %d           * ",((i*3)+j+1));
            }
            printf("\n");
        }
    }
    printf("* * * * * * * * * * * * * * * * * * * * * * * *\n");
    if(arr[8]->data != 1)
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
    for(int i=0;i<9;i++)
    {
        arr[i] = (struct Node *)malloc(sizeof(struct Node));
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

    for(int i=0;i<8;i++)
    {
        arr[i]->nextNode = arr[i+1];
    }
    for(int i=1;i<9;i++)
    {
        arr[i]->prevNode = arr[i-1];
    }

    arr[0]->data = 1;
    arr[0]->prevNode = NULL;
    arr[8]->nextNode = NULL;
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
            "   4.Game Ends When Player Reaches 9th Box.\n"
            );

    printf("\nDo U Want To Start The Game?(Y): ");
    scanf(" %c",&choice);

    if(!(choice =='Y' || choice =='y'))
    {
        exit(0);
    }
}

void Running_The_Game(struct Node *arr[9])
{
    if(arr[8]->data != 1)
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
            if(Current_Location + Dice_Got < 9)
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
                printf("\nYou Need %d Or Less To Proceed.",9-Current_Location-1);
                Running_The_Game(arr);
            }
        }
    }
    else
    {
        Printing_The_Box(arr);
    }
}

void Change_Of_Players_Location(struct Node *arr[9],int Change) //This Is Not Working
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

void Ladder_Encountered(struct Node *arr[9],struct Node *tp)
{
    for(int i=0;i<2;i++)
    {
        tp = arr[i+1];
    }
    Current_Location += 2;
}

void Snake_Encountered(struct Node *arr[9],struct Node *tp)
{
    for(int i=0;i<3;i++)
    {
        tp = arr[i-1];
    }
    Current_Location -= 3;
}