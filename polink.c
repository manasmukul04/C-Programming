#include <stdio.h>
#include <stdlib.h>
typedef struct pol
{
    int value;
    char var;
    int power;
} pol;
typedef struct node
{
    pol data;
    struct node *next;
} node;
typedef struct list
{
    node *front, *rear;
} list;
list insert(list l1, int data, int power)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data.value = data;
    temp->data.var = 'x';
    temp->data.power = power;
    temp->next = NULL;
    if (l1.front == NULL)
    {
        l1.front = temp;
        l1.rear = temp;
    }
    else
    {
        l1.rear->next = temp;
        l1.rear = temp;
    }
    return l1;
}
void display(list l1)
{
    node *temp = l1.front;
    if (temp == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    while (temp != NULL)
    {
        if (temp->data.value == 0)
        {
            temp = temp->next;
            continue;
        }
        if (temp != l1.front && temp->data.value != 0)
            printf(" + ");
        printf("%d%c^%d", temp->data.value, temp->data.var, temp->data.power);
        temp = temp->next;
    }
    printf(" = 0\n");
}
int calculate(list l1, int var, int total)
{
    int term;
    total = 0;
    node *temp = l1.front;
    while (temp != NULL)
    {
        term = 1;
        for (int i = 0; i < temp->data.power; i++)
            term = term * var;
        term = term * temp->data.value;
        total = total + term;
        temp = temp->next;
    }
    return total;
}
void compare(list l1, list l2)
{
    int var, total1, total2;
    printf("Enter the value of x.\n");
    scanf("%d", &var);
    total1 = calculate(l1, var, total1);
    printf("The value of first polynomial is: %d\n", total1);
    total2 = calculate(l2, var, total2);
    printf("The value of second polynomial is: %d\n", total2);
    if (total1 > total2)
        printf("The first polynomial is greater than second polynomial.\n");
    else if (total1 < total2)
        printf("The first polynomial is smaller than second polynomial.\n");
    else if (total1 == total2)
        printf("The first polynomial is equal to second polynomial.\n");
}
list add(list l1, list l2, list l3)
{
    node *temp1 = l1.front;
    node *temp2 = l2.front;
    int value;
    if (temp1->data.power >= temp2->data.power)
    {
        while (temp1 != NULL)
        {
            if (temp1->data.power == temp2->data.power)
            {
                value = temp1->data.value + temp2->data.value;
                l3 = insert(l3, value, temp1->data.power);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                value = temp1->data.value;
                l3 = insert(l3, value, temp1->data.power);
                temp1 = temp1->next;
            }
        }
    }
    else if (temp1->data.power < temp2->data.power)
    {
        while (temp2 != NULL)
        {
            if (temp1->data.power == temp2->data.power)
            {
                value = temp1->data.value + temp2->data.value;
                l3 = insert(l3, value, temp2->data.power);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                value = temp2->data.value;
                l3 = insert(l3, value, temp2->data.power);
                temp2 = temp2->next;
            }
        }
    }
    return l3;
}
int main()
{
    list p1, p2;
    p1.front = NULL;
    p1.rear = NULL;
    p2.front = NULL;
    p2.rear = NULL;
    int degree, coefficient, power;
    printf("Enter the highest degree of pol 1.\n");
    scanf("%d", &degree);
    printf("Enter the coefficient of highest degree and than follow in decresing order.\n");
    for (int i = 0; i <= degree; i++)
    {
        power = degree - i;
        scanf("%d", &coefficient);
        p1 = insert(p1, coefficient, power);
    }
    display(p1);
    printf("Enter the highest degree of pol 2.\n");
    scanf("%d", &degree);
    printf("Enter the coefficient of highest degree and than follow in decresing order.\n");
    for (int i = 0; i <= degree; i++)
    {
        power = degree - i;
        scanf("%d", &coefficient);
        p2 = insert(p2, coefficient, power);
    }
    display(p2);
    printf("Comparing the above given polynomial equations.\n");
    compare(p1, p2);
    list p3;
    p3.front = NULL;
    p3.rear = NULL;
    p3 = add(p1, p2, p3);
    printf("Addition of two polynomials.\n");
    display(p3);
}