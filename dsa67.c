#include <stdio.h>

#define V 6

void dfs(int graph[V][V], int visited[], int stack[], int* top, int v) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, visited, stack, top, i);
        }
    }

    stack[(*top)++] = v;
}

void topoSort(int graph[V][V]) {
    int visited[V] = {0};
    int stack[V];
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(graph, visited, stack, &top, i);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
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

    topoSort(graph);
    return 0;
}