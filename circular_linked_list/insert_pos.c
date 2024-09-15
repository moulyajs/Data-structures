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
NODE insert_pos(NODE tail, int data);
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
    tail = insert_end(tail, 10);
    tail = insert_end(tail, 20);
    printf("before insertion\n");
    display(tail);
    tail = insert_pos(tail, 40);
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
NODE insert_pos(NODE tail, int data)
{
    NODE p = tail->next;
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = data;
    temp->next = NULL;
    printf("enter position\n");
    int pos;
    scanf("%d", &pos);
    pos--;
    while (pos > 1)
    {
        p = p->next;
        pos--;
    }
    temp->next = p->next;
    p->next = temp;
    if (p == tail)
    {
        tail = tail->next;
    }
    return tail;
}