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
NODE delete_front(NODE head);
void display_end(NODE head);
int main()
{
    NODE head = NULL;

    head = insert_end(10, head);
    head = insert_end(20, head);
    head = insert_end(30, head);
    printf("before deleting\n");
    display_end(head);
    printf("after deleting\n");
    head = delete_front(head);
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
NODE delete_front(NODE head)
{
    if (head == NULL)
    {
        printf("list is empty");
    }
    NODE temp;
    temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    return head;
}
void display_end(NODE head)
{
    while (head != NULL)
    {
        printf("%d\n", head->info);
        head = head->link;
    }
}