#include <stdio.h>

#define V 5
#define E 8
#define INF 1000000000

struct Edge {
    int u, v, w;
};

void bellmanFord(struct Edge edges[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected\n");
            return;
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
}

int main() {
    struct Edge edges[E] = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    bellmanFord(edges, 0);
    return 0;
}