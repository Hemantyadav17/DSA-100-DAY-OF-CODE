// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INF 1000000000

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* createNode(int v, int w) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    int i = size++;

    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right < size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(i, smallest);
            i = smallest;
        } else break;
    }

    return top;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    Node* adj[V];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        Node* n1 = createNode(v, w);
        n1->next = adj[u];
        adj[u] = n1;

        Node* n2 = createNode(u, w);
        n2->next = adj[v];
        adj[v] = n2;
    }

    int src;
    scanf("%d", &src);

    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode top = pop();
        int u = top.node;
        int d = top.dist;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (d + w < dist[v]) {
                dist[v] = d + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);

    return 0;
}