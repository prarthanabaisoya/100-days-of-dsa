#include<stdio.h>
int main(){
    int r1,c1,r2,c2;
     printf("Enter the value of row and column for matrixA");
    scanf("%d%d",&r1,&c1);
    printf("Enter the value of row and column for matrixB");
    scanf("%d%d",&r2,&c2);
    int matrixA[r1][c1], matrixB[r2][c2];
    if(r1!=r2 && c1!=c2){
        printf("Matrix Addition is not possible");
        return 0;
    }
    printf("Enter the elements of matrixA\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
         scanf("%d", &matrixA[i][j]);
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
         printf("%d ",matrixA[i][j]);
        } printf("\n");
    }
    printf("Enter the elements of matrixB\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&matrixB[i][j]);
        }
    }
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            printf("%d ",matrixB[i][j]);
        } printf("\n");
    }

    int matrixC[r1][c1];
    printf("The resultant matrix after addition is \n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
        matrixC[i][j]= matrixA[i][j]+matrixB[i][j];
        printf("%d ", matrixC[i][j]);
    } printf("\n");
    }
   
}