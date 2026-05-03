#include <stdio.h>
#include <stdlib.h>

#define V 5
#define INF 1000000000

struct Node {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    struct Node heap[100];
};

void swap(struct Node* a, struct Node* b) {
    struct Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(struct MinHeap* h, int i) {
    while (i > 0 && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if (r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(struct MinHeap* h, int v, int dist) {
    h->heap[h->size].v = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

struct Node pop(struct MinHeap* h) {
    struct Node root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    struct MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (!isEmpty(&h)) {
        struct Node node = pop(&h);
        int u = node.v;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                push(&h, v, dist[v]);
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