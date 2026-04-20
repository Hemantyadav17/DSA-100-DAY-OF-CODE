//Find shortest distances from source vertex in a weighted graph with non-negative weights.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// structure for edge
struct Node {
    int v, w;
    struct Node* next;
};

// adjacency list
struct Node* adj[MAX];

// min heap structure
struct HeapNode {
    int vertex, dist;
};

struct Heap {
    struct HeapNode arr[MAX];
    int size;
};

// swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(struct Heap* h, int i) {
    while (i && h->arr[(i-1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[(i-1)/2], &h->arr[i]);
        i = (i-1)/2;
    }
}

// heapify down
void heapifyDown(struct Heap* h, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;

    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

// push
void push(struct Heap* h, int v, int dist) {
    h->arr[h->size].vertex = v;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// pop min
struct HeapNode pop(struct Heap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

// add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    // undirected
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = u;
    newNode->w = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct Heap heap;
    heap.size = 0;

    dist[source] = 0;
    push(&heap, source, 0);

    while (heap.size > 0) {
        struct HeapNode top = pop(&heap);
        int u = top.vertex;

        struct Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // print distances
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    printf("\n");
    return 0;
}