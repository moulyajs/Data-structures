#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void inToPost();
void push(int);
int pop();
int isEmpty();
void inToPost();
int space(char);
void display();
int post_eval();
int precedence(char);
#define MAX 100
int stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;
int main()
{
    int result;
    printf("enter the infix expression\n");
    gets(infix);
    inToPost();
    result = post_eval();
    display();
    printf("the result of postfix of expression %d\n", result);
}
void inToPost()
{
    int i, j = 0;
    char symbol, next;
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
void display()
{
    int i = 0;
    printf("the equivalent postfix expression is ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
int space(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}
void push(int c)
{
    if (top == MAX - 1)
    {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}
int pop()
{
    char c;
    if (top == -1)
    {
        printf("stack overflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int post_eval()
{
    int i, a, b;
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '/':
                push(b / a);
                break;
            case '*':
                push(b * a);
                break;
            case '^':
                push(pow(b, a));
                break;
            }
        }
    }
    return pop();
}