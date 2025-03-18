#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next, *previous;
} node;
typedef struct dclink
{
    node *front, *rear;
} list;
list insert(int data, list l1)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->previous = NULL;
    if (l1.front == NULL)
    {
        l1.front = temp;
        l1.rear = temp;
        l1.front->previous = l1.rear;
        l1.rear->next = l1.front;
    }
    else
    {
        temp->next = l1.front;
        temp->previous = l1.rear;
        l1.front->previous = temp;
        l1.rear->next = temp;
        l1.front = temp;
    }
    return l1;
}
void display(list l1)
{
    printf("The elements in the list are:\n");
    node *temp = l1.front;
    if (l1.front == NULL)
        printf("The list is empty.\n");
    else
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != l1.front);
    }
    printf("\n");
}
list insert_at_beg(int data, list l1)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = l1.front;
    temp->previous = l1.rear;
    if (l1.front == NULL)
    {
        l1.front = temp;
        l1.rear = temp;
    }
    else
    {
        l1.front->previous = temp;
        l1.rear->next = temp;
        l1.front = temp;
    }
    return l1;
}
list insert_at_end(int data, list l1)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = l1.front;
    temp->previous = l1.rear;
    if (l1.front == NULL)
    {
        l1.front = temp;
        l1.rear = temp;
    }
    else
    {
        l1.front->previous = temp;
        l1.rear->next = temp;
        l1.rear = temp;
    }
    return l1;
}
list insert_at_random(int data, list l1)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    node *dup = l1.front;
    int position, count = 1;
    printf("Enter the position of insertion.\n");
    scanf("%d", &position);
    if (position < 1)
    {
        printf("Invalid position, insertion not possible.\n");
        return l1;
    }
    else if (position == 1)
        return insert_at_beg(data, l1);
    while (dup->next != l1.front)
    {
        if (count == position - 1)
        {
            temp->next = dup->next;
            temp->previous = dup;
            dup->next->previous = temp;
            dup->next = temp;
        }
        dup = dup->next;
        count++;
    }
    if (count < position)
        printf("Invalid position.\n");
    return l1;
}
list del_at_beg(list l1)
{
    node *temp = l1.front;
    if (temp == NULL)
    {
        printf("Empty list.\n");
        return l1;
    }
    l1.front = temp->next;
    l1.front->previous = l1.rear;
    l1.rear->next = l1.front;
    return l1;
}
list del_at_end(list l1)
{
    node *temp = l1.rear;
    if (temp == NULL)
    {
        printf("Empty list.\n");
        return l1;
    }
    l1.rear = temp->previous;
    l1.rear->next = l1.front;
    l1.front->previous = l1.rear;
    return l1;
}
list del_an_element(list l1)
{
    node *temp = l1.front;
    if (l1.front == NULL)
    {
        printf("Empty list.\n");
        return l1;
    }
    printf("Enter the element to be deleted.\n");
    int element, count = 0;
    scanf("%d", &element);
    while (temp->next != l1.front)
    {
        if (temp->data == element)
        {
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            count++;
        }
        temp = temp->next;
    }
    if (count == 0)
        printf("Element not present in the list.\n");
    return l1;
}
int main()
{
    list l1;
    l1.front = NULL;
    l1.rear = NULL;
    int number, element;
    printf("Enter the no. of elements to be entered.\n");
    scanf("%d", &number);
    int arr[number];
    printf("Insert the element.\n");
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &arr[i]);
        l1 = insert(arr[i], l1);
    }
    display(l1);
    printf("Enter the element to be inserted at the beginning.\n");
    scanf("%d", &element);
    l1 = insert_at_beg(element, l1);
    display(l1);
    printf("Enter the element to be inserted at the end.\n");
    scanf("%d", &element);
    l1 = insert_at_end(element, l1);
    display(l1);
    printf("Enter the element to be inserted at specific position.\n");
    scanf("%d", &element);
    l1 = insert_at_random(element, l1);
    display(l1);
    printf("Deletion of beginnig element.\n");
    l1 = del_at_beg(l1);
    display(l1);
    printf("Deletion of end element.\n");
    l1 = del_at_end(l1);
    display(l1);
    printf("Deletion of specific element.\n");
    l1 = del_an_element(l1);
    display(l1);
}