#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 5
int choice, item, front, rear, q[QUE_SIZE];
void InsertQ();
int DeleteQ();
void Display();
void main()
{
    front = 0;
    rear = -1;
    while (1)
    {
        printf("1.insert 2.delete\n");
        printf("3.display 4.exit\n");
        printf("please enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("element to be inserted\n");
            scanf("%d", &item);
            InsertQ();
            break;
        case 2:
            item = DeleteQ();
            if (item == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("item deleted = %d\n", item);
            }
            break;
        case 3:
            Display();
            break;
        default:
            exit(0);
            break;
        }
    }
}
void InsertQ()
{
    if (rear == QUE_SIZE - 1)
    {
        printf("queue overflow\n");
        // return;
    }
    else
    {
        rear = rear + 1;
        q[rear] = item;
    }
}
int DeleteQ()
{
    if (front > rear)
    {
        return -1;
    }
    else
    {
        return q[front++];
    }
}

void Display()
{
    int i;
    if (front > rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("contents of the queue\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", q[i]);
        }
    }
}