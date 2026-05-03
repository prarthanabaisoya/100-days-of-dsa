#include <stdio.h>

#define V 4

int dfs(int graph[V][V], int visited[], int recStack[], int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            if (!visited[i] && dfs(graph, visited, recStack, i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(int graph[V][V]) {
    int visited[V] = {0};
    int recStack[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(graph, visited, recStack, i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int graph[V][V] = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,1,0,0}
    };

    if (hasCycle(graph))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}