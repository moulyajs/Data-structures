#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;
NODE create_node(int data);
NODE insert_end(NODE tail, int data);
void display(NODE tail);
NODE create_node(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}
NODE insert_end(NODE tail, int data)
{
    if (tail == NULL)
    {
        return tail;
    }
    NODE new = (NODE)malloc(sizeof(struct node));
    NODE temp = tail->next;
    new->info = data;

    new->next = temp;
    new->prev = tail;
    tail->next = new;
    temp->prev = new;
    tail = new;

    return tail;
}
int main()
{
    int data;

    NODE tail;
    tail = create_node(10);
    printf("before insertion\n");
    display(tail);
    printf("enter elements\n");
    for (int i = 1; i < 3; i++)
    {
        scanf("%d", &data);
        tail = insert_end(tail, data);
    }
    printf("after insertion\n");
    display(tail);
}
void display(NODE tail)
{
    NODE temp;
    temp = tail->next;
    do
    {
        printf("%d\n", temp->info);
        temp = temp->next;
    } while (temp != tail->next);
}
