#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    int count;
};

int compare(const void* a, const void* b) {
    struct Candidate* c1 = (struct Candidate*)a;
    struct Candidate* c2 = (struct Candidate*)b;

    if (c1->count != c2->count)
        return c2->count - c1->count;

    return strcmp(c1->name, c2->name);
}

int main() {
    char votes[][50] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny"};
    int n = sizeof(votes) / sizeof(votes[0]);

    struct Candidate* arr = (struct Candidate*)malloc(n * sizeof(struct Candidate));
    int size = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < size; j++) {
            if (strcmp(arr[j].name, votes[i]) == 0) {
                arr[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(arr[size].name, votes[i]);
            arr[size].count = 1;
            size++;
        }
    }

    qsort(arr, size, sizeof(struct Candidate), compare);

    printf("%s\n", arr[0].name);

    free(arr);
    return 0;
}