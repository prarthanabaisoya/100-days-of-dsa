#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    printf("%d %d\n", lowerBound(arr, n, x), upperBound(arr, n, x));
    return 0;
}
