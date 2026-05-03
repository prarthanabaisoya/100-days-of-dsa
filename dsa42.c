#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x)
{
    if(rear == MAX-1)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int isQueueEmpty()
{
    return front > rear;
}

int isStackEmpty()
{
    return top == -1;
}

int main()
{
    int n, x;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    
    while(!isQueueEmpty())
    {
        push(dequeue());
    }

    
    while(!isStackEmpty())
    {
        enqueue(pop());
    }

 
    while(!isQueueEmpty())
    {
        printf("%d ", dequeue());
    }

    return 0;
}