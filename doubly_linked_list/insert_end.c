#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
void display(NODE head);
NODE insert_end(NODE head, int item);
NODE create_node(NODE head, int item);
NODE create_node(NODE head, int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    head = temp;
    return head;
}
NODE insert_end(NODE head, int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    NODE cur = head;
    while (cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;

    return head;
}
int main()
{
    NODE head = NULL;

    int item;
    head = create_node(head, 45);
    printf("enter elements\n");
    for (int i = 0; i < 3; i++)
    {

        scanf("%d", &item);
        head = insert_end(head, item);
    }
    printf("elements are\n");
    display(head);
    return 0;
}
void display(NODE head)
{
    NODE temp;
    temp = head;
    while (temp != NULL)
    {

        printf("%d\n", temp->info);
        temp = temp->rlink;
    }
}
