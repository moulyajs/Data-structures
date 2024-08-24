#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE insert_front(int element, NODE head);
void display_front(NODE head);
int main()
{
    NODE head = NULL;

    int element;
    printf("enter elements\n");
    for (int i = 0; i < 3; i++)
    {

        scanf("%d", &element);
        head = insert_front(element, head);
    }
    display_front(head);
    return 0;
}
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("no memory");
        exit(0);
    }
    return x;
}
NODE insert_front(int element, NODE head)
{
    NODE temp;
    temp = getnode();
    temp->info = element;
    temp->link = head;
    head = temp;
    return head;
}
void display_front(NODE head)
{
    printf("entered elemets\n");
    while (head != NULL)
    {
        printf("%d\n", head->info);
        head = head->link;
    }
}
