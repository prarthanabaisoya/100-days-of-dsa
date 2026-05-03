#include <stdio.h>
int main(){
    int arr[7] ={4,3,5,7,6,2,1};
    int smallest =arr[0];
    for(int i=1; i<7; i++){

        if(arr[i]<smallest){
        smallest = arr[i];
        }
     }
     for(int j=0;j<7;j++){
        printf("%d ",arr[j]);
     }
     for(int k=0;k<7;k++){
     printf("Found at %d",arr[k]);
     }
}