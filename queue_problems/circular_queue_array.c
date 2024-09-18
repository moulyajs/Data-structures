#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 5
int choice, item, front, rear, q[QUE_SIZE], count = 0;
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
    if (count == QUE_SIZE)
    {
        printf("queue overflow\n");
    }

    else
    {
        rear = (rear + 1) % QUE_SIZE;
        q[rear] = item;
        count++;
    }
}
int DeleteQ()
{
    int item;
    if (count == 0)
    {
        return -1;
    }
    else
    {
        item = q[front];
        front = (front + 1) % QUE_SIZE;
        count -= 1;
        return item;
    }
}
void Display()
{
    int i, temp = front;
    if (count == 0)
    {
        printf("queue is empty\n");
        return;
    }
    printf("contents of the queue\n");
    for (i = 0; i < count; i++)
    {
        printf("%d\n", q[temp]);

        temp = (temp + 1) % QUE_SIZE;
    }
}