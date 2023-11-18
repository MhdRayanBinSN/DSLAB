#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void main()
{
    struct node *top = NULL, *temp;
    int ch,item;
    while (1)
    {
        printf("Choices are:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("Your choice was: %d\n", ch);
        switch (ch)
        {
        case 1:
            printf("enter element to be pushed: ");
            scanf("%d", &item);
            temp = (struct node *)malloc(sizeof(struct node));
            if(temp==NULL){
                printf("No insertion possible");
            }
            temp->data = item;
            temp->link = top;
            top = temp;
            break;
        case 2:
            if (top == NULL)
                printf("Stack is empty: Underflow\n");
            else
            {
                temp = top;
                printf("Deleted element is: %d", temp->data);
                top = top->link;
                temp->link = NULL;
                free(temp);
                break;
            case 3:
                if (top == NULL)
                    printf("Stack is empty: \n");
                else
                {
                    temp = top;
                    printf("Stack elements are: ");
                    while (temp != NULL)
                    {
                        printf("%d ", temp->data);
                        temp = temp->link;
                    }
                   // printf("\nTop = %d",top->data);
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid input\n");
            }
            printf("\n");
        }
    }
}
