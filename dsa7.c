#include<stdio.h>
int main(){
    int i,j,p,k;
    int arr[7]={1,2,3,4,5,6,7};
    scanf("%d",&p);
    for(i=p;i<7;i++){
        arr[i]=arr[i+1];
    }
    for(i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}