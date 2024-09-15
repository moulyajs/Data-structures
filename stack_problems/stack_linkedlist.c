#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *top = NULL;
void push(int data);
int pop();
void display();
int isEmpty();
int main()
{
    while (1)
    {
        int choice, data;
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter ur choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter element to be inserted\n");
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
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("no memory");
        exit(1);
    }
    newnode->data = data;
    newnode->link = NULL;
    newnode->link = top;
    top = newnode;
}
void display()
{
    struct node *temp;
    temp = top;
    if (isEmpty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    printf("stack elements are\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}
int pop()
{
    if (isEmpty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    struct node *temp;
    temp = top;
    int val = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return val;
}
int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}