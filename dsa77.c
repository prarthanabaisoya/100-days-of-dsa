#include <stdio.h>

#define V 5

void dfs(int graph[V][V], int visited[], int v) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

int isConnected(int graph[V][V]) {
    int visited[V] = {0};

    dfs(graph, visited, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) return 0;
    }
    return 1;
}

int main() {
    int graph[V][V] = {
        {0,1,1,0,0},
        {1,0,1,0,0},
        {1,1,0,1,0},
        {0,0,1,0,1},
        {0,0,0,1,0}
    };

    if (isConnected(graph))
        printf("Connected\n");
    else
        printf("Not Connected\n");

    return 0;
}