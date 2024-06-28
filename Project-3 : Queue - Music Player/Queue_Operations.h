// By HyperHBR--Hardiksinh Rathod 

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

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

void peekQueue(struct queue *q)
{
    if(isEmptyQueue(q))
    {
        printf("Queue Is Empty");
    }
    else
    {
        printf("%d Is In The Front Of The Queue\n",q->arr[q->front]);
    }
}

void traverseQueue(struct queue *q)
{
    printf("\n\nPrinting All Elements Of Queue:\n");
    int i;
    if(q->front<q->rear)
    {
        for(i = q->front ;i <= q->rear ;i++)
        {
            printf("%d\n",q->arr[i]);
        }
    }
    else if(q->front==q->rear)
    {
        printf("%d\n",q->arr[q->front]);
    }
    else
    {
        for(i = q->front ;i < q->size ;i++)
        {
            printf("%d\n",q->arr[i]);
        }
        for(i = 0  ;i <= q->rear ;i++)
        {
            printf("%d\n",q->arr[i]);
        }
    }
}