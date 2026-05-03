#include<stdio.h>
#define MAX 5

int dq[MAX];
int front = -1;
int rear = -1;

void push_front(int x){
    if((front==0 && rear==MAX-1) || (front==rear+1)){
        printf("Overflow\n");
        return;
    }

    if(front==-1){
        front=rear=0;
    }
    else if(front==0){
        front=MAX-1;
    }
    else{
        front--;
    }

    dq[front]=x;
}

void push_back(int x){
    if((front==0 && rear==MAX-1) || (front==rear+1)){
        printf("Overflow\n");
        return;
    }

    if(front==-1){
        front=rear=0;
    }
    else if(rear==MAX-1){
        rear=0;
    }
    else{
        rear++;
    }

    dq[rear]=x;
}

void pop_front(){
    if(front==-1){
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n",dq[front]);

    if(front==rear){
        front=rear=-1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else{
        front++;
    }
}

void pop_back(){
    if(front==-1){
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n",dq[rear]);

    if(front==rear){
        front=rear=-1;
    }
    else if(rear==0){
        rear=MAX-1;
    }
    else{
        rear--;
    }
}