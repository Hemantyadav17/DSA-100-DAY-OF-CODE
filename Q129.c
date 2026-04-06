//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

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
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    Node* adj[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, visited, i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}