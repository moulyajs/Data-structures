#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack_arr[MAX];
int top = -1;
void push(int data);
int pop();
int isFull();
int isEmpty();
void display();
int main()
{
    int choice, data;
    while (1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter ur choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter element to be pushed\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("deleted element %d\n", data);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
}
void push(int data)
{
    if (isFull())
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        stack_arr[top] = data;
    }
}
int pop()
{
    if (isEmpty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    else
    {
        int value = stack_arr[top];
        top = top - 1;
        return value;
    }
}
void display()
{
    if (top == -1)
    {
        printf("stack underflow\n");
        return;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack_arr[i]);
        }
    }
}
int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}