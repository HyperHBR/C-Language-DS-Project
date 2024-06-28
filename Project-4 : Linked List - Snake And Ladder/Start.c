#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prevNode;
    struct Node *nextNode;
};

void linkedListTraversal(struct Node *head)
{
    if(head==NULL)
    {
        printf("\nLinked List Does Not Exist\n");
    }
    else
    {
        struct Node *tp = head;
        while(tp->nextNode != NULL)
        {
            printf("%d\n",tp->data);
            tp = tp->nextNode;
        } 
        printf("%d",tp->data);
    }
}

int main()
{
    //Allocating Memory For Nodes In Heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    //Linking 1st And 2nd Node
    head->prevNode = NULL;
    head->data = 7;
    head->nextNode = second;

    //Linking 2nd And 3rd Node
    second->prevNode = head;
    second->data = 8;
    second->nextNode = third;

    //Linking 4th And 3rd Node
    third->prevNode = second;
    third->data = 11;
    third->nextNode = fourth;

    //Terminating The List At Third Node
    fourth->prevNode = third;
    fourth->data = 41;
    fourth->nextNode = NULL;

    linkedListTraversal(head);
    return 0;
}