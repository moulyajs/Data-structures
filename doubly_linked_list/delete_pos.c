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
NODE delete_pos(NODE head, int pos);

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
    int pos;
    scanf("%d", &pos);
    printf("before deletion\n");
    display(head);

    head = delete_pos(head, pos);
    printf("after deletion\n");
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
NODE delete_pos(NODE head, int pos)
{
    NODE prev, cur;
    prev = head;
    cur = head;
    if (head == NULL)
    {
        printf("list is empty");
        return NULL;
    }
    else if (pos == 1)
    {
        head = cur->rlink;
        free(cur);
        cur = NULL;
        return head;
    }
    else
    {
        while (pos != 1)
        {
            prev = cur;
            cur = cur->rlink;
            pos--;
            if (cur == NULL)
            {
                printf("invalid position\n");
                return head;
            }
        }

        prev->rlink = cur->rlink;
        free(cur);
        cur = NULL;
        return head;
    }
}
