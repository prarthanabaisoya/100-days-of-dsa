#include <stdio.h>
struct node {
    int data;
    struct node* next;
};
struct node* num(struct node* head){
    int count = 0;
    struct node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next; 
    } return count;
}
int main(){
    struct node* head = NULL;
    printf("%d",num(&head));
}