#include <stdio.h>
#include <stdlib.h>

#define V 6

void topologicalSort(int graph[V][V]) {
    int indegree[V] = {0};
    int queue[V];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (graph[i][j])
                indegree[j]++;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    int count = 0;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < V; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
        count++;
    }

    if (count != V)
        printf("\nCycle detected\n");
}

int main() {
    int graph[V][V] = {
        {0,0,0,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    topologicalSort(graph);
    return 0;
}