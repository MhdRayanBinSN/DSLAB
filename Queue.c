#include <stdio.h>
void main(){
    int item,n ,option,Q[10] ,i;
    int front =-1 , rear =-1;
    printf("Enter the size of queue : ");
    scanf("%d",&n);
    do{
        printf("\n     Menu\n1.Enqueue \n2.Dequeue \n3.Display \n4. quit\nEnter the option: ");
        scanf("%d",&option);
        switch (option){
         case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d",&item);
            if(rear==n-1){
                printf("Queue is full");
            }else if(rear == -1){
                front =0;rear =0;
                Q[rear] = item;
            }else{
                rear = rear +1;
                Q[rear] = item;
            }
            break;
        case 2:
            if(front == -1){
                printf("Queue is empty");
            }else if(front == rear){
                printf("Deleted item : %d",Q[front]);
                front=rear =-1;
            }else{
                printf("Deleted item : %d",Q[front]);
                front = front +1;
            }
            break;
        case 3:
            if (front==-1){
                printf("Queue is empty");
            }else{
                for(i=front;i<=rear;i++){
                    printf("%d\t",Q[i]);
                }
                printf("\nFornt = %d, Rear = %d",front,rear);
            }
            break;
        case 4:
            break;
        default:
            printf("invalid entry");
        }
    }while(option!=4);
}