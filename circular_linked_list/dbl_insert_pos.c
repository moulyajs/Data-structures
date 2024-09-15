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
NODE insert_pos(NODE tail, int data);
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
    tail = insert_end(tail, 20);
    tail = insert_end(tail, 30);
    printf("before insertion\n");
    display(tail);
    tail = insert_pos(tail, 100);
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
    int pos;
    scanf("%d", &pos);
    if (tail == NULL)
    {
        return tail;
    }
    NODE new = (NODE)malloc(sizeof(struct node));
    NODE temp = tail->next;
    new->info = data;
    pos--;
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    new->prev = temp;
    new->next = temp->next;
    NODE temp2;
    temp2 = temp->next;
    temp2->prev = new;
    temp->next = new;
    if (temp == tail)
    {
        tail = tail->next;
    }
    return tail;
}