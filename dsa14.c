#include <stdio.h>
int main(){
    int i ,j, k;
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    } 
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                if(arr[i][j] != 0){
                    printf("NOT a square matrix.");
                    return 0;
                }
            }else if(i=j){
                if(arr[i][j] != 1){
                    printf("Not a square matrix.");
                    return 0;
                }
            }
        }
    } printf("Square MATRIX.");
}