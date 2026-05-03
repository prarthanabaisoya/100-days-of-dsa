#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int longestZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    int hash[2 * SIZE + 1];
    for (int i = 0; i < 2 * SIZE + 1; i++) hash[i] = -2;

    hash[SIZE] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int idx = sum + SIZE;

        if (hash[idx] != -2) {
            int len = i - hash[idx];
            if (len > maxLen) maxLen = len;
        } else {
            hash[idx] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", longestZeroSum(arr, n));
    return 0;
}