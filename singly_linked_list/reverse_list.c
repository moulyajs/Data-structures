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
NODE reverse_list(NODE head);
void display_end(NODE head);
int main()
{
    NODE head = NULL;

    head = insert_end(10, head);
    head = insert_end(20, head);
    head = insert_end(30, head);
    head = insert_end(40, head);
    head = insert_end(50, head);
    printf("before reversing\n");
    display_end(head);
    printf("after reversing\n");
    head = reverse_list(head);
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
NODE reverse_list(NODE head)
{
    NODE prev, next;
    prev = NULL;
    next = NULL;
    if (head == NULL)
    {
        printf("list is empty");
        return NULL;
    }
    else
    {
        while (head != NULL)
        {
            next = head->link;
            head->link = prev;
            prev = head;
            head = next;
        }
        head = prev;
        return head;
    }
}
void display_end(NODE head)
{
    if (head == NULL)
    {
        printf("list is empty \n");
    }
    while (head != NULL)
    {
        printf("%d\n", head->info);
        head = head->link;
    }
}