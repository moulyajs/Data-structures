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
NODE delete_pos(NODE tail);
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
    NODE p = tail->next;
    int pos;
    scanf("%d", &pos);
    pos--;
    while (pos > 1)
    {
        p = p->next;
        pos--;
    }
    NODE temp = p->next;
    p->next = temp->next;
    if (temp == tail)
    {
        tail = temp;
    }
    free(temp);
    temp = NULL;
    return tail;
}