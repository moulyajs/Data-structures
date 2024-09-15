#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
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
    return temp;
}
NODE insert_end(NODE tail, int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = data;
    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
    return tail;
}
int main()
{
    int data;

    NODE tail;
    tail = create_node(30);
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
