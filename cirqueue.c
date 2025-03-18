#include <stdio.h>
#include <stdlib.h>
#define size 5
typedef struct queue
{
    int data[size];
    int front, rear;
} queue;
void create(queue *q1)
{
    q1->front = -1;
    q1->rear = -1;
}
void isEmpty(queue *q1)
{
    if (q1->rear == q1->front == -1)
        printf("Queue underflow.\n");
    else
        printf("Queue is not empty.\n");
}
void isFull(queue *q1)
{
    if ((q1->rear+ 1) % 5 == q1->front)
        printf("Queue overflow.\\n");
    else
        printf("Queue is not full.\n");
}
void enqueue(queue *q1, int data)
{
    if (isFull(q1) == 0)
    {
        if (q1->front == -1)
            q1->front = 0;
        q1->rear = (q1->rear + 1) % size;
        q1->arr[q1->rear] = data;
    }
    else
    {
        printf("Queue is Full, can't insert %d\n", data);
    }
}
void dequeue(queue *q1)
{
    int *arr;
    arr = (int *)malloc(sizeof(int));
    if (q1->front == -1)
    {
        printf("Queue underflow. No element dequeued.\n");
        return;
    }
    else
    {
        if(q1->front == size - 1)
            q1->front = 0;
        arr[0] = q1->data[q1->front];
        if (q1->rear == q1->front)
        {
            q1->front = -1;
            q1->rear = -1;
        }
        else
            q1->front++;
    }
    printf("The dequed element is: %d.\n", arr[0]);
    free(arr[0]);
    return;
}
void display(queue *q1)
{
    if (q1->front == -1)
        printf("Queue underflow.");
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (i >= q1->front && i < q1->rear + 1)
                printf("|%d|", q1->data[i]);
            else
                printf("|_|");
        }
    }
    printf("\n");
}
int main()
{
    queue q1;
    printf("Creating a queue.\n");
    create(&q1);
    printf("Checking the initial empty condition for the queue.\n");
    isEmpty(&q1);
    printf("Checking the initial full condition for the queue.\n");
    isFull(&q1);
    printf("Inserting elements in the queue.\n");
    int number, element;
    printf("Enter the number of elements to be inserted.\n");
    scanf("%d", &number);
    printf("Enter the elements.\n");
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &element);
        enqueue(&q1, element);
    }
    printf("Dispalying the queue.\n");
    display(&q1);
    printf("Enter the number of elements to be removed.\n");
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        dequeue(&q1);
    }
    printf("Dispalying the queue.\n");
    display(&q1);
    printf("Enter the number of elements to be inserted.\n");
    scanf("%d", &number);
    printf("Enter the elements.\n");
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &element);
        enqueue(&q1, element);
    }
    display(&q1);
    printf("Enter the number of elements to be removed.\n");
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        dequeue(&q1);
    }
    printf("Dispalying the queue.\n");
    display(&q1);
}