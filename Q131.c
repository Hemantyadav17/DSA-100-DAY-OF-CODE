//Problem: Detect cycle in directed graph using DFS and recursion stack.

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

int dfs(Node* adj[], int vis[], int path[], int node) {
    vis[node] = 1;
    path[node] = 1;

    Node* temp = adj[node];
    while (temp) {
        int u = temp->val;

        if (!vis[u]) {
            if (dfs(adj, vis, path, u))
                return 1;
        }
        else if (path[u]) {
            return 1;
        }

        temp = temp->next;
    }

    path[node] = 0;
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    Node* adj[V];
    int vis[V], path[V];

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        vis[i] = 0;
        path[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(adj, vis, path, i)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}