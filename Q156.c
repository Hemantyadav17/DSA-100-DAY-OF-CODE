// Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing
// which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int V;
int *adj[MAX];
int size[MAX];

int disc[MAX], low[MAX], parent[MAX], visited[MAX], ap[MAX];
int timer = 0;

void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent[u] == -1 && children > 1)
                ap[u] = 1;

            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent[u]) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int m;
    scanf("%d %d", &V, &m);

    // initialize
    for (int i = 0; i < V; i++) {
        size[i] = 0;
        visited[i] = 0;
        parent[i] = -1;
        ap[i] = 0;
        adj[i] = (int*)malloc(MAX * sizeof(int)); // allocate max possible
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    int found = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    printf("\n");

    return 0;
}