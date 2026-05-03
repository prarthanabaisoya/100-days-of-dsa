#include <stdio.h>
int main(){
    int n,k;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    for(int j=0;j<n;j++){
        scanf("%d",&arr[j]);
    }
    printf("enter k:");
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i]=temp;
    }
    for(int j=0;j<n;j++){
        printf("%d ",arr[j]);
    }
}