#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) return -1;
    struct Node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int evaluate(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            if (exp[i] == '+') push(a + b);
            else if (exp[i] == '-') push(a - b);
            else if (exp[i] == '*') push(a * b);
            else if (exp[i] == '/') push(a / b);
        }
    }
    return pop();
}

int main() {
    char exp[] = "23*54*+9-";
    printf("%d\n", evaluate(exp));
    return 0;
}