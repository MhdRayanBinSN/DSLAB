#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
void main(){
    struct node *front=NULL,*rear=NULL,*ptr,*temp;
    int item , optn;
    do{
        printf("\n1.Enqueue\n2.Deque\n3.Display\n4.Quit");
        printf("\nEnter the choice: ");
        scanf("%d",&optn);
        switch(optn){
            case 1:
                temp = (struct node *)malloc(sizeof(struct node));
                printf("Enter item:  ");
                scanf("%d",&temp->data);
                item = temp->data;
                temp->link = NULL;
                if(front==NULL){
                    front = rear = temp;
                }else{
                    rear->link = temp;
                    rear = temp;
                }
                break;
            case 2:
                if(front==NULL){
                    printf("QUEUE is empty");
                }else if(front==rear){
                    temp = front;
                    front = rear = NULL;
                    free(temp);
                }else{
                    temp = front;
                    printf("deleted item: %d",temp->data);
                    front = front->link;
                    free(temp);
                }
                break;
            case 3:
                if(front==NULL){
                    printf("\nQUEUE is empty..");
                }else
                {
                    ptr=front;
                    printf("\nQueue : ");
                    while (ptr!=NULL)
                    {
                        printf("%d ",ptr->data);
                        ptr = ptr->link;
                    }
                    
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid Entry");
        }
    }while(optn!=4);
}