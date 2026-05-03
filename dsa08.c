#include <stdio.h>
int power(int x,int n){
    if(n==0){
        return 1;
    }else if(n%2==0){
      int y = power(x,(n/2));
      return y*y;
    }else{
        return x*power(x,n-1);
    }
}
int main(){
    int x,n;
    printf("Enter x and n\n");
    scanf("%d%d",&x,&n);
    printf("%d",power(x,n));
}