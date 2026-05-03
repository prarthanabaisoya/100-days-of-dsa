#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int idx = (h + i * i) % SIZE;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
}

int search(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int idx = (h + i * i) % SIZE;

        if (table[idx] == key)
            return idx;

        if (table[idx] == -1)
            return -1;
    }

    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d ", table[i]);
    printf("\n");
}
int main() {
    init();
    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);
    display();
    printf("%d\n", search(25));
    printf("%d\n", search(99));
    return 0;
}