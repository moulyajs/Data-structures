#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node *NODE;
NODE create_node(int data);
void display(NODE tail);
NODE create_node(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = data;
    temp->next = temp;
    return temp;
}
int main()
{
    int data;
    scanf("%d", &data);
    NODE tail;
    tail = create_node(data);
    printf("node created");
    display(tail);
}
void display(NODE tail)
{
    NODE temp;
    temp = tail->next;
    while (temp != tail->next)
    {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}
