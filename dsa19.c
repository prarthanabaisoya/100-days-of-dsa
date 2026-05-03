#include <stdio.h>
int main(){
    int n,k;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    for(int j=0;j<n;j++){
        scanf("%d",&arr[j]);
    }
    int min = arr[0]+arr[0];
    for(k=0;k<n;k++){
        for(int i=1;i<n;i++){
            if(arr[k]+arr[i]< min){
                min = arr[k]+arr[i];
            }
        }
    }
    printf("%d",min);
}