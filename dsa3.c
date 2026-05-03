// minimum extra space used is one 
// #include <stdio.h>
// int main(){
//     int i,j,c,n=7;
//     int arr[7]={1,2,3,4,5,6,7};
//     for( i=0;i<=(n/2);i++) {
//          c = arr[i];
//          arr[i]=arr[6-i];
//          arr[6-i]=c;
//     }
//     for(i=0;i<7;i++){
//         printf("%d ",arr[i]);
//     }
// }
#include <stdio.h>
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    //int *c;  
    for(int i=0; i<(7/2); i++){
       int *c=&arr[i];
        arr[i]=arr[6-i];
        arr[6-i]=*c;
    } 
     for(int i=0;i<7;i++){
         printf("%d ",arr[i]);
    }
    return 0;
}