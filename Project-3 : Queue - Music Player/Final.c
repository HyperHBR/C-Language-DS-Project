#include <stdio.h> //For Input Output Processes
#include <math.h> //For Mathematical Manipulation
#include <string.h> //For Manupulating String
#include <stdlib.h> //For Dynamic Memory Allocation And Clear Screen On MAC

struct Songs_Types
{
    int num;
    char type[30];
    int SongStartsFrom;
    int SongEndsAt;
};

struct Songs_Types Types[6] = {
                                1,"Hollywood Songs",0,4,
                                2,"Bollywood Songs",4,8,
                                3,"Punjabi Songs",8,13,
                                4,"Gujarati Songs",13,18,
                                5,"Garbo Songs",18,20,
                                6,"Old Bollywood Songs",20,23,
};

struct Song_Name_And_Codes
{
    int num;
    char name[30];
};

struct Song_Name_And_Codes Names_And_Codes[23]={
                                1, "See You Again",
                                3, "Closer", 
                                2, "Heat Waves", 
                                4, "Bella Ciao", 
                                5, "Kesariya", 
                                6, "Phir Kabhi", 
                                7, "Tu Aake Dekhle", 
                                8, "Namo Namo", 
                                9, "We Rollin", 
                                10, "Brown Munde", 
                                11, "Back Bone", 
                                12, "Wakhra", 
                                13, "Lehanga", 
                                14, "Ganu Jeevo", 
                                15, "Shan Bhan Bhule", 
                                16, "Sapna Vinai Ni Raat", 
                                17, "Dhun Lagi", 
                                18, "Vhalam Aavo Ne", 
                                19, "Manada Lidha Mohi", 
                                20, "Vaagyo Re Dhol", 
                                21, "Lag Jaa Gale", 
                                22, "Kya Hua Tera Wada", 
                                23, "O Mere Dil Ke Chain",
                                };   

struct stack
{
    int size;
    int top;
    int *arr;
}sp,sp2;

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

int pop(struct stack *ptr)
{
    if(isEmptyStack(ptr))
    {
        printf("---Stack Underflow---\n");
        return NULL;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
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

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
}q;

int isEmptyQueue(struct queue *q)
{
    if(q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFullQueue(struct queue *q)
{
    if((q->front > q->rear) && ((q->front+q->rear) == q->size))
    {
        return 1;
    }
    else if((q->front < q->rear) && ((q->rear - q->front) == q->size-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q,int value)
{
    if(isFullQueue(q))
    {
        printf("\nQueue Is Full\n");
    }
    else
    {
        if(q->rear < q->size-1)
        {
            q->rear++;
            q->arr[q->rear] = value;
        }
        else if((q->rear == q->size-1) && q->front!=0)
        {
            q->rear = 0;
            q->arr[q->rear] = value;
        }
        else
        {
            return;
        }

        if(q->front == -1)
        {
            q->front++;
        }
    }
}

int dequeue(struct queue *q)
{
    if(isEmptyQueue(q))
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
        else if(q->front == q->size-1)
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

void traverseQueue(struct queue *q)
{
    int i;
    if(q->front<q->rear)
    {
        for(i = q->front ;i <= q->rear ;i++)
        {
            printf("%s -- Song Code : ",Names_And_Codes[q->arr[i]].name);
            printf("%d\n",q->arr[i]);
        }
    }
    else if(q->front==q->rear)
    {
        printf("%s -- Song Code : ",Names_And_Codes[q->arr[i]].name);
        printf("%d\n",q->arr[q->front]);
    }
    else
    {
        for(i = q->front ;i < q->size ;i++)
        {
            printf("%s -- Song Code : ",Names_And_Codes[q->arr[i]].name);
            printf("%d\n",q->arr[i]);
        }
        for(i = 0  ;i <= q->rear ;i++)
        {
            printf("%s -- Song Code : ",Names_And_Codes[q->arr[i]].name);
            printf("%d\n",q->arr[i]);
        }
    }
}

void Display_Song_Types();
void Display_Songs_Name_And_Code();
int RangeCheck(int i,int low,int high); //Function To Check Range Of i
void Display_Songs_In_Playlist();
void Song_Completed_Or_Next_Song_From_Queue();
void Song_Completed_Or_Prev_Song_From_Stack1();
void Song_Completed_Or_Next_Song_From_Stack2();
void Prev_Song();

int Song_Type_Selected;

int main()
{
    q.size = 30;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));

    sp.size = 30;
    sp.top = -1; //Initially Empty
    sp.arr = (int *)malloc(sizeof(int));

    sp2.size = 30;
    sp2.top = -1; //Initially Empty
    sp2.arr = (int *)malloc(sizeof(int));

    Display_Song_Types();
}


int RangeCheck(int i,int low,int high) //Function To Check Range Of i
{
    if((i>=low && i<=high))
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
    scanf("%d",&Song_Type_Selected);
    if(!RangeCheck(Song_Type_Selected,1,6))
    {
        system("clear");
        printf("\nInvalid Choice!!");
        Display_Song_Types();
    }
    else
    {
        system("clear");
        Display_Songs_Name_And_Code();
    }
    Display_Songs_In_Playlist();
}

void Display_Songs_Name_And_Code()
{
    int code;
    char choice;

    for(int i=Types[Song_Type_Selected-1].SongStartsFrom;i<Types[Song_Type_Selected-1].SongEndsAt;i++)
            printf("%d - %s\n",Names_And_Codes[i].num,Names_And_Codes[i].name);

    printf("\nWhich Song Do U Want To Add In Playlist : ");
    scanf("%d",&code); 

    if(RangeCheck(code,Types[Song_Type_Selected-1].SongStartsFrom+1,Types[Song_Type_Selected-1].SongEndsAt))
    {
        enqueue(&q,code);
    }
    else
    {
        system("clear");
        printf("\n Invalid Choice!! \n\n");
        Display_Songs_Name_And_Code();
    }

    printf("\nDo U Want To Add More Songs?(Y) : ");
    scanf(" %c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        system("clear");
        Display_Song_Types();
    }
}

void Display_Songs_In_Playlist()
{
    char choice;
    printf("Do U Want To Display Songs That You Have Added?(Y) : ");
    scanf(" %c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        char more;

        system("clear");
        printf("\nYou Have Selected The Following Songs:\n");
        traverseQueue(&q);
        printf("\nDo You Want To Add/Delete Songs : (A) : ");
        scanf(" %c",&more);
        if(more == 'A' || more == 'a')
        {
            system("clear");
            Display_Song_Types();
        }
    }
}

void Song_Completed_Or_Next_Song_From_Queue()
{
    int song_code = dequeue(&q);
    push(&sp,song_code);
}

void Song_Completed_Or_Prev_Song_From_Stack1()
{
    int song_code = pop(&sp);
    push(&sp2,song_code);
}

void Song_Completed_Or_Next_Song_From_Stack1()
{
    int song_code = pop(&sp2);
    push(&sp1,song_code);
}

// void play()
// {
//     char songname[100];
//     printf("Enter songname:");
//     scanf("%s",&songname);
//     PlaySound(songname,NULL,SND_ASYNC);
//     printf("Playing Song....");
// }
// void stop()
// {
//     PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
// }



