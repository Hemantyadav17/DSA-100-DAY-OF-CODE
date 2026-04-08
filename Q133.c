//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
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

void dfs(Node* adj[], int visited[], int stack[], int* top, int v) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->val]) {
            dfs(adj, visited, stack, top, temp->val);
        }
        temp = temp->next;
    }

    stack[(*top)++] = v;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    Node* adj[V];
    int visited[V], stack[V];
    int top = 0;

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(adj, visited, stack, &top, i);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}