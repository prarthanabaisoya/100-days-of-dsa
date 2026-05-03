#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* merge(struct node* head,struct node* head2){
    struct node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = head2;
    return head;
}
int main(){
    struct node* head = NULL;
    struct node* head2 = NULL;
    int n,i=0,v;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    while (i<n){
        printf("enter the value of newnode:");
        scanf("%d",&v);
        struct node* newnode;
        newnode -> data  = v;
        newnode -> next = NULL;
        if(head == NULL){
            head = newnode;
            return head;
        }
        struct node* temp = head;
        while (temp -> next = NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
        return head;
    }
    printf("%d",merge(head,head2));
}