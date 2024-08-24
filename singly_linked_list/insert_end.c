#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE insert_end(int element, NODE head);
NODE getnode();
void display_end(NODE head);
int main()
{
    NODE head = NULL;
    int element;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &element);
        head = insert_end(element, head);
    }
    display_end(head);
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
void display_end(NODE head)
{
    while (head != NULL)
    {
        printf("%d\n", head->info);
        head = head->link;
    }
}