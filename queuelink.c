#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct queuelink
{
    node *front, *rear;
} queue;
queue create(queue q1)
{
    q1.front = NULL;
    q1.rear = NULL;
    return q1;
}
void isEmpty(queue q1)
{
    printf("Checking for empty condition.\n");
    if (q1.front == NULL)
        printf("Queue underflow.\n");
    else
        printf("Queue is not empty.\n");
}
queue enqueue(queue q1, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (q1.front == NULL)
    {
        q1.front = temp;
        q1.rear = temp;
    }
    else
    {
        q1.rear->next = temp;
        q1.rear = temp;
    }
    return q1;
}
queue dequeue(queue q1)
{
    if (q1.front == NULL)
    {
        printf("Queue underflow.\n");
        return q1;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    temp = q1.front;
    q1.front = q1.front->next;
    printf("The dequeued element is: %d\n", temp->data);
    free(temp);
    return q1;
}
void display(queue q1)
{
    printf("Displaying the elements in the queue.\n");
    if (q1.front == NULL)
    {
        printf("Queue underflow.\n");
        return;
    }
    node *temp = q1.front;
    while (temp != NULL)
    {
        printf("| %d |", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void front(queue q1)
{
    printf("Displaying the front element: ");
    if (q1.front == NULL)
    {
        printf("Queue underflow.\n");
        return;
    }
    printf("%d\n", q1.front->data);
}
void rear(queue q1)
{
    printf("Displaying the rear element: ");
    if (q1.front == NULL)
    {
        printf("Queue underflow.\n");
        return;
    }
    printf("%d\n", q1.rear->data);
}
int main()
{
    queue q1;
    printf("Creating a queue using link list.\n");
    q1 = create(q1);
    isEmpty(q1);
    printf("Enter the number of elements to be inserted in the queue.\n");
    int number, element;
    scanf("%d", &number);
    printf("Insert the elements.\n");
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &element);
        q1 = enqueue(q1, element);
    }
    display(q1);
    front(q1);
    rear(q1);
    isEmpty(q1);
    printf("Enter the number of elements to be removed from the queue.\n");
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
        q1 = dequeue(q1);
    display(q1);
    front(q1);
    rear(q1);
    isEmpty(q1);
}
