#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int m=n;
    int rev = 0,rem;
    while(n!=0){
       rem = n%10;
        rev += rem*10;
        n /= 10;
    }
    if(rev == m){
        printf("%d is pallindrome",m);
    }
}