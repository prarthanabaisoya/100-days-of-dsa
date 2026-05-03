// structure ques,memory allocation,boolean,sorting
#include <stdio.h>
int main(){
    int arr[7]={4,3,5,7,6,2,1};
    int c,i,j;
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)
      {
            if(arr[i]<arr[j])
            {
                c=arr[i];
                arr[i]=arr[j];
                arr[j]=c;
            }
        }
    }
    for(i=0;i<7;i++)
    {
        printf(" %d",arr[i]);
    }
    return 0;
}