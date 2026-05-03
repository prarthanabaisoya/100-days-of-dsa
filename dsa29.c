#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if (head == NULL || head->exp < e) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->exp >= e)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    poly1 = insert(poly1, 5, 2);
    poly1 = insert(poly1, 4, 1);
    poly1 = insert(poly1, 2, 0);

    poly2 = insert(poly2, 5, 1);
    poly2 = insert(poly2, 5, 0);

    struct Node* result = addPoly(poly1, poly2);

    display(poly1);
    display(poly2);
    display(result);

    return 0;
}