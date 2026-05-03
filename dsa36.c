#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d", &n);

    int q[n];
    int front = 0, rear = -1, size = 0;

    
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % n;
        q[rear] = x;
        size++;
    }

    scanf("%d", &m);

    
    for(int i = 0; i < m; i++)
    {
        int temp = q[front];         
        front = (front + 1) % n;
        size--;

        rear = (rear + 1) % n;       
        q[rear] = temp;
        size++;
    }

    
    for(int i = 0; i < size; i++)
    {
        printf("%d ", q[(front + i) % n]);
    }

    return 0;
}