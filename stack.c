#include <stdio.h>
#define MAX 3
int top = -1, stack[MAX];
void push(int item);
int pop();
void display();
void main()
{
    int choice, item,i;
    do{
        printf("\n     Menu\n1.push\n2.pop\n3.Display all stack element\n5.quit");
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            printf("\nPopped item:%d", item);
            break;
        case 3:
            if (top == -1)
            {
                printf("\nStak under flow");
            }
            printf("Stack Elements : ");
            for (i = 0; i <=top; i++)
            {
                printf("%d ", stack[i]);
            }
            printf("\n");
            printf("Top position= %d",top);
            break;
        case 4:
            break;
        default:
            printf("Wrong choice");
        }
    }while(choice!=4);
}
void push(int item)
{
    if (top < MAX - 1)
    {
        top = top + 1;
        stack[top] = item;
    }
    else if (top == MAX - 1)
    {
        printf("\nStack over flow");
        return;
    }
}
int pop()
{
    int item;
    if (top == -1)
    {
        printf("\nStak under flow");
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return item;
    }
}
