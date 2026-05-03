#include <stdio.h>
#include <stdlib.h>

    int* merge(int *A[],int *B[],int m,int n){
    int  *merged = (int*)malloc((m+n)*sizeof(int));
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    for(int p = 0;p<m;p++){
        scanf("%d",&A[p]);
    }
    for(int q = 0;q<n;q++){
        scanf("%d",&B[q]);
    }
    while(i >= 0 && j >= 0){
        if(A[i] > B[j]){
            merged[k--]=A[i--];
        }
        else{
            merged[k--]=B[j--];
        }
    }
    while(j>=0){
        merged[k--]=B[j--];
    }
    free(merged);
    return merged;
} 