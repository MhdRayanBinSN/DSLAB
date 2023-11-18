#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int top = -1;
char infix[MAX],postfix[MAX],stack[MAX];

int isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}

int space(char c)
{
    if(c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

void push(char c)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow!");
        exit(0);
    }
    
    top= top+1;
    stack[top] = c;
}

char pop()
{
    if(top == -1)
    {
        printf("Stack underflow!!");
        exit(0);
    }
    
    int c = stack[top];
    top--;
    return c;
}

int precedence(char c)
{
    switch(c)
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

void print()
{
    for(int i = 0 ; i < strlen(postfix) ; i++)
    {
        printf("%c",postfix[i]);
    }
    printf("\n");
}

int main()
{
    int i,j = 0;
    char symbol,next;
    printf("Enter the infix expression : ");
    gets(infix);

    for(i = 0; i < strlen(infix) ; i++)
    {
        symbol = infix[i];
        if(!space(symbol))
        {
            switch(symbol)
            {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while(next = pop() != '(')
                        postfix[j++] = next;
                    break;
                case '+':
                case '-':
                case '^':
                case '/':
                case '*':

                    while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                        postfix[j++] = pop();
                    push(symbol);
                    break;
                default:
                 postfix[j++] = symbol;
            }
        }
    }

    while(!isEmpty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    print();

    return 0;
}