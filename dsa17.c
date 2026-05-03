#include <stdio.h>
int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    }
    int max = arr[0];
    int min = arr[0];
    for(int i=0;i<n;i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    printf("%d\n",min);
    for (int j=0;j<n;j++){
        if(max < arr[j]){
            max = arr[j];
        }
    }
    printf("%d\n",max);
}