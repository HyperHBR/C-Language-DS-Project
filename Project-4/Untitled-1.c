#include <stdio.h>  //For Input Output Processes
#include <math.h>   //For Mathematical Manipulation
#include <string.h> //For Manupulating String
#include <stdlib.h> //For Dynamic Memory Allocation And Clear Screen On MAC
#include <windows.h> //For Acessing CMD Controls
#include <MMSystem.h>

int count = 0;//For Further Use

struct Songs_Types //Creating The Song Structure
{
    int num;
    char type[30];
    int SongStartsFrom; //For Displaying List
    int SongEndsAt;
};

struct Songs_Types Types[6] = {
    1,
    "Hollywood Songs",
    0,
    4,
    2,
    "Bollywood Songs",
    4,
    8,
    3,
    "Punjabi Songs",
    8,
    13,
    4,
    "Gujarati Songs",
    13,
    18,
    5,
    "Garbo Songs",
    18,
    20,
    6,
    "Old Bollywood Songs",
    20,
    23,
};

struct Song_Name_And_Codes //Structure For Song Names And Codes
{
    int num;
    char name[30];
};

struct Song_Name_And_Codes Names_And_Codes[23] = {
    1,
    "See You Again",
    2,
    "Closer",
    3,
    "Heat Waves",
    4,
    "Bella Ciao",
    5,
    "Kesariya",
    6,
    "Phir Kabhi",
    7,
    "Tu Aake Dekhle",
    8,
    "Namo Namo",
    9,
    "We Rollin",
    10,
    "Brown Munde",
    11,
    "Back Bone",
    12,
    "Wakhra",
    13,
    "Lehanga",
    14,
    "Ganu Jeevo",
    15,
    "Shan Bhan Bhule",
    16,
    "Sapna Vinai Ni Raat",
    17,
    "Dhun Lagi",
    18,
    "Vhalam Aavo Ne",
    19,
    "Manada Lidha Mohi",
    20,
    "Vaagyo Re Dhol",
    21,
    "Lag Jaa Gale",
    22,
    "Kya Hua Tera Wada",
    23,
    "O Mere Dil Ke Chain",
};
int Available(char ch,char ch2);

struct queue //Structure For Creating Queue
{
    int size;
    int front;
    int rear;
    int *arr;
} q;

int isEmptyQueue(struct queue *q) //Empty Queue Function
{
    if (q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFullQueue(struct queue *q)//Full Queue Function
{
    if ((q->front > q->rear) && ((q->front + q->rear) == q->size))
    {
        return 1;
    }
    else if ((q->front < q->rear) && ((q->rear - q->front) == q->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int value) //For Enqueuing A Value/Song
{
    if (isFullQueue(q))
    {
        printf("\nQueue Is Full\n");
    }
    else
    {
        if (q->rear < q->size - 1)
        {
            q->rear++;
            q->arr[q->rear] = value;
        }
        else if ((q->rear == q->size - 1) && q->front != 0)
        {
            q->rear = 0;
            q->arr[q->rear] = value;
        }
        else
        {
            return;
        }

        if (q->front == -1)
        {
            q->front++;
        }
    }
}

int dequeue(struct queue *q)//DeQueue Function
{
    if (isEmptyQueue(q))
    {
        return -1;
    }
    else
    {
        int value;
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else if (q->front == q->size - 1)
        {
            q->front = 0;
        }
        else
        {
            q->front++;
        }
        value = q->arr[q->front];
        return value;
    }
}

void traverseQueue(struct queue *q) //For Displaying Songs/Elements Of Queue
{
    int i;
    if (q->front < q->rear)
    {
        for (i = q->front; i <= q->rear; i++)
        {
            printf("%s -- Song Code : ", Names_And_Codes[q->arr[i]-1].name);
            printf("%d\n", q->arr[i]);
        }
    }
    else if (q->front == q->rear)
    {
        printf("%s -- Song Code : ", Names_And_Codes[q->arr[i]-1].name);
        printf("%d\n", q->arr[q->front]);
    }
    else
    {
        for (i = q->front; i < q->size; i++)
        {
            printf("%s -- Song Code : ", Names_And_Codes[q->arr[i]-1].name);
            printf("%d\n", q->arr[i]);
        }
        for (i = 0; i <= q->rear; i++)
        {
            printf("%s -- Song Code : ", Names_And_Codes[q->arr[i]].name);
            printf("%d\n", q->arr[i]);
        }
    }
}

void Display_Song_Types(); //For Displaying Song Types
void Display_Songs_Name_And_Code(); //For Showing Song Code And Name
int RangeCheck(int i, int low, int high); // Function To Check Range Of i
void Display_Songs_In_Playlist(); //For Displaying Sogns In Playlist
void Song_Completed_Or_Next_Song_From_Queue(); //Checking It SOng Has Been Played Or Not
void display_option();

void play(); //For Playing The Song
void stop(); //For Stopping The Song

int Song_Type_Selected;

int main()
{
    //QUeue Initialization
    q.size = 30;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    

    int ch;
    Display_Song_Types();
    
    while (1)
    {
        printf("1 -> Play The Song\n");
		printf("2 -> Stop The Song\n");
		printf("3 -> Exit From Code\n");
        printf("Enter The Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            play();
            break;
        case 2:
            stop();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice...\n");
            printf("Please Enter again...");
        }
    }
}

int RangeCheck(int i, int low, int high) // Function To Check Range Of i
{
    if ((i >= low && i <= high))
        return 1;
    else
        return 0;
}

void Display_Song_Types()
{
    printf("\nThese Are All The Available Songs With Us:\n");
    printf("\n1-Hollywood Songs");
    printf("\n2-Bollywood Songs");
    printf("\n3-Punjabi Songs");
    printf("\n4-Gujarati Songs");
    printf("\n5-Garbo Songs");
    printf("\n6-Old Bollywood Songs");

    printf("\n\nWhich Type Of Song Would You Like To Add : ");
    scanf("%d", &Song_Type_Selected);
    if (!RangeCheck(Song_Type_Selected, 1, 6))
    {
        system("@cls||clear");
        printf("\nInvalid Choice!!");
        Display_Song_Types();
        Display_Songs_In_Playlist();
    }
    else
    {
        system("@cls||clear");
        Display_Songs_Name_And_Code();
    }
}

void Display_Songs_Name_And_Code()
{
    int code;
    char choice;
    int i;

    for (i = Types[Song_Type_Selected - 1].SongStartsFrom; i < Types[Song_Type_Selected - 1].SongEndsAt; i++)
        printf("%d - %s\n", Names_And_Codes[i].num, Names_And_Codes[i].name);

    printf("\nWhich Song Do U Want To Add In Playlist : ");
    scanf("%d", &code);

    if (RangeCheck(code, Types[Song_Type_Selected - 1].SongStartsFrom + 1, Types[Song_Type_Selected - 1].SongEndsAt))
    {
        enqueue(&q, code);
        count++;
    }
    else
    {
        system("@cls||clear");
        printf("\n Invalid Choice!! \n\n");
        Display_Songs_Name_And_Code();
    }

    printf("\nDo U Want To Add More Songs?(Y/N) : ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        system("@cls||clear");
        Display_Song_Types();
    }
}

void Display_Songs_In_Playlist()
{
    char choice;
    printf("Do U Want To Display Songs That You Have Added?(Y) : ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        char more;

        system("@cls||clear");
        printf("\nYou Have Selected The Following Songs:\n");
        traverseQueue(&q);
        printf("\nDo You Want To Add/Delete Songs : (A) : ");
        scanf(" %c", &more);
        if (more == 'A' || more == 'a')
        {
            system("@cls||clear");
            Display_Song_Types();
        }
    }
}


void play()
{
	
    //Display_Songs_In_Playlist();
    printf("\nYou Have Selected The Following Songs:\n");
    traverseQueue(&q);
    char songname[10];
    printf("Enter Song_Code:");
    scanf("%s", songname);
    if (Available(songname[0],songname[1]))
    {
        PlaySound(songname, NULL, SND_ASYNC);
        printf("Playing Song....\n");
    }
    else
    {
        printf("Invalid choice");
        play();
    }

    // PlaySound(songname,NULL,SND_ASYNC);
    // printf("Playing Song....");
}
void stop()
{
    PlaySound(TEXT("STOPPED"), NULL, SND_APPLICATION);
}
int Available(char ch,char ch2)
{
    int flag = 0;
    int n = (int)ch;
    int n2 =  (int)ch2;
    n2 = n2 - 48;
    n = n -48;
    if(n2<=9 && n2>=0)
    {
    	n = n*10 + n2;
	}
    
    int i;
    for (i = 0; i < count; i++)
    {
        if (q.arr[i] == n)
        {
            flag++;
            break;
        }
    }
    if (flag > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}