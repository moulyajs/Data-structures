#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

NODE create_node(NODE head, int item);
void display(NODE head);
int main()
{
    NODE head = NULL;
    int item;
    scanf("%d", &item);
    head = create_node(head, item);
    printf("elements in list\n");
    display(head);
}
NODE create_node(NODE head, int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    head = temp;
    return head;
}
void display(NODE head)
{
    NODE temp;
    temp = head;
    while (temp != NULL)
    {

        printf("%d", temp->info);
        temp = temp->rlink;
    }
}
