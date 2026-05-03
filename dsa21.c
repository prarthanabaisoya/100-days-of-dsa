#include  <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* createnode(struct node* head){
    int value;
    printf("Enter value:");
    scanf("%d",&value);
    struct node* newnode = malloc(sizeof(struct node));
    if (!newnode) return head;
    newnode -> data = value;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
    }else{
        struct node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        } 
        temp -> next = newnode;
    } 
    return head;
}
int main(){
    struct node* head = NULL;
    int n;
    scanf("%d",&n);
    while(n!=0){
        head = createnode(head);
        n--;
    }
    struct node* temp = head;
    while(temp != NULL){
        printf("%d->",temp-> data);
        temp = temp -> next;
    } return 0;
}