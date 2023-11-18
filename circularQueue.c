#include <stdio.h>
void main(){
    int item,n ,option,CQ[10] ,i,front =-1 , rear =-1;
    printf("Enter the size of queue : ");
    scanf("%d",&n);
    do{
        printf("\n    Menu\n1.Enqueue\n2.Dequeue\n3.Display \n4. quit\nEnter the option: ");
        scanf("%d",&option);
        switch (option){
         case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d",&item);
            if((rear+1)%n==front){
                printf("Circular Queue is full");
            }else if(rear == -1){
                front =0;rear =0;
                CQ[rear] = item;
            }else{
                rear = (rear+1)%n;
                CQ[rear] = item;
            }
            break;
        case 2:
            if(front == -1 ){
                printf("Queue is empty");
            }else if(front == rear){
                printf("Deleted item : %d",CQ[front]);
                front=rear =-1;
            }else{
                printf("Deleted item : %d",CQ[front]);
                front = (front +1)%n;
            }
            break;
        case 3:
            if (front==-1){
                printf("Circular Queue is empty");
            }else if(front<=rear){
                printf("\nCircular Queue: ");
                for(i=front;i<=rear;i++){
                    printf("%d\t",CQ[i]);
                }
                printf("\nFront = %d, Rear = %d",front,rear);
            }else{
                printf("Circular Queue: ");
                for(i=rear;i<=n-1;i++){
                    printf("%d\t",CQ[i]);
                }
                printf("\nFront = %d, Rear = %d",front,rear);
            }
            break;
        case 4:
            break;
        default:
            printf("invalid entry");
        }
    }while(option!=4);
}