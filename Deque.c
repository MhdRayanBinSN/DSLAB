#include <stdio.h>
void main()
{
    int item, n, option, Q[10], i,front = -1, rear = -1;
    printf("Enter the size of queue : ");
    scanf("%d", &n);
    do
    {
        printf("\n   Menu\n1.Push\n2.Inject\n3.pop\n4.eject\n5.Display\n6.quit\nEnter the option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            if (front == 0 && rear == n - 1){
                printf("Queue is full");
            }
            else if (rear == -1){
                front = 0;
                rear = 0;
                Q[rear] = item;
            }
            else if(front > 0){
                front --;
                Q[front] =item;
            }else{
                printf("Insertion is not possible");
            }
            break;
        case 2:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            if (front ==0 && rear == n - 1){
                printf("Queue is full");
            }
            else if (rear == -1){
                front = 0;
                rear = 0;
                Q[rear] = item;
            }
            else if(rear<n-1){
                rear++;
                Q[rear] = item;
            }
            else{
                for(i=front;i<=rear;i++){
                    Q[i-1] = Q[i];
                }
                Q[rear] = item;
                front --;
            }
            break;
        case 3:
            if (front == -1){
                printf("Queue is empty");
            }
            else if (front == rear){
                printf("Deleted item : %d", Q[front]);
                front = rear = -1;
            }
            else{
                printf("Deleted item : %d", Q[front]);
                front = front + 1;
            }
            break;
        case 4:
            if (front == -1){
                printf("Queue is empty");
            }
            else if (front == rear){
                printf("Deleted item : %d", Q[front]);
                front = rear = -1;
            }
            else{
                printf("Deleted item : %d", Q[front]);
                rear--;
            }
            break;
        case 5:
            if (front == -1){
                printf("Queue is empty");
            }
            else{
                for (i = front; i <= rear; i++)
                {
                    printf("%d\t", Q[i]);
                }
                printf("\nFront = %d, Rear = %d",front,rear);
            }
            break;
        case 6:
            break;
        default:
            printf("invalid entry");
        }
    } while (option != 6);
}