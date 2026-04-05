//Problem: Perform BFS from a given source using queue.

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

void bfs(Node* adj[], int n, int s) {
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        Node* temp = adj[curr];
        while (temp) {
            if (!visited[temp->val]) {
                visited[temp->val] = 1;
                queue[rear++] = temp->val;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

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

    int s;
    scanf("%d", &s);

    bfs(adj, n, s);

    return 0;
}