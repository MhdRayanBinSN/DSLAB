#include <stdio.h>
void transpose();
void sparse(int A[10][10],int r,int c);
void main(){
    int i,j,A[10][10],r,c;
    printf("Enter the number of rows and coloumns of the matrix: ");
    scanf("%d%d",&r,&c);

    printf("Enter the matrix: ");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&A[i][j]);
        }
    }
    sparse(A,r,c);
    transpose();
}
int s[10][10],t[10][10];
void sparse(int A[10][10],int r,int c){
    int i,j,k=1;
    s[0][0] = r;
    s[0][1] = c;
    //for storing
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(A[i][j]!=0){
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = A[i][j];
                k++;
            }
        }
    }
    //for printing
    s[0][2] = k-1;
    printf("\n Tuple form  \n");
    for(i=0;i<=s[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
}
void transpose(){
    int r,c,k,i,j;
    t[0][0] = s[0][1];
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];
    k=1;
    r = s[0][1];
    c = s[0][2];
    //for storing
    for(i=0;i<r;i++){
        for(j=0;j<=c;j++){
            if(s[j][1]==i){
                t[k][0] = s[j][1];
                t[k][1] = s[j][0];
                t[k][2] = s[j][2];
                k++;
            }
        }
    }
    //for printing
    printf("\n Transpose\n");
    for(i=0;i<=t[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",t[i][j]);
        }
        printf("\n");
    }
}