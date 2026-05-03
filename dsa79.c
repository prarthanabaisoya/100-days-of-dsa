#include <stdio.h>

#define V 5
#define INF 1000000000

int minDistance(int dist[], int visited[]) {
    int min = INF, index = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 10, INF, 30, 100},
        {INF, 0, 50, INF, INF},
        {INF, INF, 0, INF, 10},
        {INF, INF, 20, 0, 60},
        {INF, INF, INF, INF, 0}
    };

    dijkstra(graph, 0);
    return 0;
}