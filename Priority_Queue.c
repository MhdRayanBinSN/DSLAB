#include <stdio.h>
void main()
{
    int item, priority, n, option, Q[10], P[10], i;
    int front = -1, rear = -1;
    printf("Enter the size of priority queue: ");
    scanf("%d", &n);
    do
    {
        printf("\n    Menu\n1.Enqueue \n2.Dequeue \n3.Display \n4. quit");
        printf("\nEnter the option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &item);
            printf("Enter the priority: ");
            scanf("%d", &priority);
            if (front == 0 && rear == n - 1)
            {
                printf("Queue is full");
            }
            else if (front == -1 && rear == -1)
            {
                front = 0;
                rear = 0;
                Q[rear] = item;
                P[rear] = priority;
            }
            else
            {
                if (rear == n - 1)
                {
                    for (i = front; i <= rear; i++)
                    {
                        Q[i - 1] = Q[i];
                        P[i - 1] = P[i];
                    }
                    front--;
                    rear--;
                }
                for (i = rear; i >= front; i--)
                {
                    if (P[i] < priority)
                    {
                        break;
                    }
                }
                int loc = i + 1;
                for (i = rear; i >= loc; i--)
                {
                    Q[i + 1] = Q[i];
                    P[i + 1] = P[i];
                }
                Q[loc] = item;
                P[loc] = priority;
                rear++;
            }
            break;
        case 2:
            if (front == -1)
            {
                printf("Queue is empty");
            }
            else if (front == rear)
            {
                printf("\nDeleted item : %d", Q[front]);
                front = rear = -1;
            }
            else
            {
                printf("\nDeleted item : %d", Q[front]);
                front = front + 1;
            }
            break;
        case 3:
            if (front == -1)
            {
                printf("Queue is empty");
            }
            else
            {
                for (i = front; i <= rear; i++)
                {
                    printf("%d\t", Q[i]);
                }
                printf("\n");
                for (i = front; i <= rear; i++)
                {
                    printf("%d\t", P[i]);
                }
            }
            break;
        case 4:
            break;
        default:
            printf("invalid entry");
        }
    } while (option != 4);
}