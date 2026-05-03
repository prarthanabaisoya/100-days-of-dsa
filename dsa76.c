#include <stdio.h>

#define V 6

void dfs(int graph[V][V], int visited[], int v) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

int countComponents(int graph[V][V]) {
    int visited[V] = {0};
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            count++;
        }
    }

    return count;
}

int main() {
    int graph[V][V] = {
        {0,1,0,0,0,0},
        {1,0,0,0,0,0},
        {0,0,0,1,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,1},
        {0,0,0,0,1,0}
    };

    printf("%d\n", countComponents(graph));
    return 0;
}