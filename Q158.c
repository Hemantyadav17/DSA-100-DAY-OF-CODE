// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][],
// where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// adjacency list
int *adj[MAX], *rev[MAX];
int size1[MAX], size2[MAX];

int visited[MAX];
int stack[MAX], top = -1;

// DFS 1 (fill stack)
void dfs1(int u) {
    visited[u] = 1;

    for (int i = 0; i < size1[u]; i++) {
        int v = adj[u][i];
        if (!visited[v])
            dfs1(v);
    }

    stack[++top] = u;
}

// DFS 2 (on reversed graph)
void dfs2(int u) {
    visited[u] = 1;

    for (int i = 0; i < size2[u]; i++) {
        int v = rev[u][i];
        if (!visited[v])
            dfs2(v);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // initialize
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(MAX * sizeof(int));
        rev[i] = (int*)malloc(MAX * sizeof(int));
        size1[i] = size2[i] = 0;
        visited[i] = 0;
    }

    // input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size1[u]++] = v;
        rev[v][size2[v]++] = u; // reverse graph
    }

    // step 1: fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs1(i);
    }

    // reset visited
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // step 2: process stack
    int scc = 0;

    while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            dfs2(node);
            scc++;
        }
    }

    printf("%d\n", scc);

    return 0;
}