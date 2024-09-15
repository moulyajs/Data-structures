/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 30
int stack[MAX_SIZE];
int top;
char postfix[100];
void push(int value);
int pop();
int eval();
int main()
{
    top = -1;
    scanf("%s", postfix);
    int result = eval();
    printf("%d", result);
}
int eval()
{
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (isdigit(postfix[i]))
        {
            push();
        }
        else
        {
            int oper1 = pop();
            int oper2 = pop();
            switch (postfix[i])
            {
                int r;
            case '+':
                r = oper1 + oper2;

            case '-':
                r = oper1 - oper2;

            case '*':
                r = oper1 * oper2;
            case '/':
                r = oper1 / oper2;
            }
        }
    }
    push(r);
}
void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top--];
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    // Enter your code here. Read input from STDIN. Print output to STDOUT
    int m, n;
    int sensor1[20];
    int sensor2[20];
    int result[20];
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &sensor1[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sensor2[i]);
    }
    int greater = -1;
    for (int i = 0; i < m; i++)

    {
        for (int j = 0; j < n; j++)
        {

            if (sensor1[i] == sensor2[j])
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (sensor2[k] > sensor1[i])
                    {
                        greater = sensor2[j + 1];
                    }

                    else
                    {
                        result[i] = greater;
                    }
                }
            }
        }
    }
    printf("[");
    for (int i = 0; i < m; i++)
    {
        if (i + 1 == m)

            printf("%d", result[i]);

        else
            printf("%d,", result[i]);
    }
    printf("]");

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 3 + 2 * 6 / 2;
    printf("%d", a);
}