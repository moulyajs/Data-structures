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
NODE delete_list(NODE head);
void display_end(NODE head);
int main()
{
    NODE head = NULL;

    head = insert_end(10, head);
    head = insert_end(20, head);
    head = insert_end(30, head);
    printf("before deleting\n");
    display_end(head);
    head = delete_list(head);
    if (head == NULL)
    {
        printf("successfully deleted the list");
    }
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
NODE delete_list(NODE head)
{
    if (head == NULL)
    {
        printf("list is empty");
        return NULL;
    }
    NODE temp;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head); // temp becomes null at the end of loop so as head
        head = temp;
    }

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