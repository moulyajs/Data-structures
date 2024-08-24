#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE insert_pos(int element, int pos, NODE head);
NODE insert_end(int element, NODE head);
NODE getnode();
void display_pos(NODE head);

int main()
{
    NODE head = NULL;
    int element, pos;
    head = insert_end(10, head);
    head = insert_end(20, head);
    head = insert_end(30, head);
    head = insert_end(40, head);
    head = insert_end(50, head);
    printf("enter element\n");
    scanf("%d", &element);
    printf("enter position\n");
    scanf("%d", &pos);

    head = insert_pos(element, pos, head);
    display_pos(head);
}
NODE insert_end(int element, NODE head)
{
    NODE temp, cur;
    temp = getnode();
    temp->info = element;
    temp->link = NULL;
    if (head == NULL)
    {
        return temp;
    }
    else
    {
        cur = head;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = temp;
    }
    return head;
}
NODE insert_pos(int element, int pos, NODE head)
{
    NODE temp, cur;

    temp = getnode();
    temp->info = element;
    temp->link = NULL;
    cur = head;

    if (pos == 1)
    {
        temp->link = head;
        return temp;
    }

    for (int i = 1; i < pos - 1 && cur != NULL; i++)
    {
        cur = cur->link;
    }
    if (cur == NULL)
    {
        printf("Invalid position\n");
        return head;
    }
    temp->link = cur->link;
    cur->link = temp;
    return head;
}
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("no memory");
    }
    return x;
}
void display_pos(NODE head)
{
    while (head != NULL)
    {
        printf("%d\n", head->info);
        head = head->link;
    }
}
