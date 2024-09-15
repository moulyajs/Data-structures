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
NODE delete_pos(NODE tail);
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
    printf("before deletion\n");
    display(tail);
    tail = delete_pos(tail);
    printf("after deletion\n");
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
NODE delete_pos(NODE tail)
{
    if (tail == NULL)
    {
        return tail;
    }
    if (tail->next == tail)
    {

        free(tail);
        tail = NULL;
        return tail;
    }
    int pos;
    scanf("%d", &pos);
    NODE temp = tail->next;

    // pos--;
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    NODE temp2;
    temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    if (temp == tail)
    {
        tail = temp2;
    }
    free(temp);
    temp = NULL;

    return tail;
}