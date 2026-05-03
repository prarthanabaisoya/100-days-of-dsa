#include <stdio.h>
int main(){
    int n,symmetric;
    scanf("%d",&n);
    int matrix[n][n];
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }  
    for (int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(matrix[i][j] != matrix[j][i]){
                symmetric=0;
                break;
            }
        } 
    }
    if(symmetric){
        printf("Matrix is symmetric.");
    }else{
        printf("Matrix is not symmetric.");
    }
}