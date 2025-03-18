#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct stackbinary
{
    int top;
    int size;
    int *arr;
} stack;
void create(stack *s1, int temp)
{
    int binary;
    s1->size = 0;
    for (int i = 0; temp > 0; i++)
    {
        binary = temp % 2;
        temp = temp / 2;
        s1->size++;
    }
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    s1->top = -1;
}
void push(stack *s1, int binary)
{
    s1->arr[s1->top + 1] = binary;
    s1->top++;
}
void display(stack *s1, int number)
{
    printf("Displaying binary equivalent in stack.\n");
    if (number < 0)
        printf("| - |\n");
    for (int i = s1->size - 1; i >= 0; i--)
        printf("| %d |\n", s1->arr[i]);
}
int main()
{
    stack s1;
    printf("Conversion of decimal number to its binary eqivalent.\n");
    int number, binary , temp;
    printf("Enter a decimal number: ");
    scanf("%d", &number);
    temp = number;
    if (temp < 0)
        temp = temp * (-1);
    create(&s1, temp);
    for (int i = 0; temp > 0; i++)
    {
        binary = temp % 2;
        temp = temp / 2;
        push(&s1, binary);
    }
    display(&s1, number);
}
