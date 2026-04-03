// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

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

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* temp = adj[i];
        while (temp) {
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}