#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    printf("Enter the string without spaces:");
    scanf("%s",s);

    for(int j=strlen(s)-1 ;j>=0;j--){
        printf("%c",s[j]);
    }
    return 0;
 }
