// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

//Note: The graph can have multiple component.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = v;
    temp->next = NULL;
    return temp;
}

int dfs(Node* adj[], int visited[], int v, int parent) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        int u = temp->val;

        if (!visited[u]) {
            if (dfs(adj, visited, u, v))
                return 1;
        } else if (u != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    Node* adj[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Node* n1 = createNode(v);
        n1->next = adj[u];
        adj[u] = n1;

        Node* n2 = createNode(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    int hasCycle = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(adj, visited, i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}