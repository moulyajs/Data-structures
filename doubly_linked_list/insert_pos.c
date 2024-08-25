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
NODE insert_pos(NODE head, int item);
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

    head = create_node(head, 45);
    head = insert_end(head, 30);
    head = insert_end(head, 80);
    int item;
    printf("enter the item to be inserted\n");
    scanf("%d", &item);
    head = insert_pos(head, item);
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
NODE insert_pos(NODE head, int item)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->info = item;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    NODE temp, temp2;
    temp = head;
    temp2 = NULL;
    int pos;
    printf("enter position\n");
    scanf("%d", &pos);
    pos--;
    while (pos != 1)
    {
        temp = temp->rlink;
        pos--;
        if (temp == NULL)
        {
            printf("invalid position\n");
            return head;
        }
    }

    if (temp->rlink == NULL)
    {
        temp->rlink = newNode;
        newNode->llink = temp;
    }
    else
    {
        temp2 = temp->rlink;
        temp->rlink = newNode;
        temp2->llink = newNode;
        newNode->llink = temp;
        newNode->rlink = temp2;
    }
    return head;
}