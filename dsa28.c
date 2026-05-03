#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        last->next = last;
        return last;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    return last;
}

void traverse(struct Node* last) {
    if (last == NULL)
        return;

    struct Node* temp = last->next;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

int main() {
    struct Node* last = NULL;

    last = insert(last, 10);
    last = insert(last, 20);
    last = insert(last, 30);
    last = insert(last, 40);

    traverse(last);

    return 0;
}