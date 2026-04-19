// Problem Statement
//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX];
    int visited[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // start from node 1

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;
        int min = INT_MAX;

        // find minimum key vertex not visited
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // update neighbors
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}