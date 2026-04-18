//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where 
//connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int time = 0;

void dfs(int u, int parent, int* disc, int* low, int** graph, int* size,
         int** result, int* returnSize) {

    disc[u] = low[u] = time++;

    for (int i = 0; i < size[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, graph, size, result, returnSize);

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            // critical connection
            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSize,
                         int** returnColumnSizes) {

    int** graph = malloc(n * sizeof(int*));
    int* size = calloc(n, sizeof(int));

    // count neighbors
    for (int i = 0; i < connectionsSize; i++) {
        size[connections[i][0]]++;
        size[connections[i][1]]++;
    }

    // allocate adjacency list
    for (int i = 0; i < n; i++) {
        graph[i] = malloc(size[i] * sizeof(int));
        size[i] = 0;
    }

    // fill graph
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        graph[u][size[u]++] = v;
        graph[v][size[v]++] = u;
    }

    int* disc = malloc(n * sizeof(int));
    int* low = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
    }

    int** result = malloc(connectionsSize * sizeof(int*));
    for (int i = 0; i < connectionsSize; i++) {
        result[i] = malloc(2 * sizeof(int));
    }

    *returnSize = 0;

    dfs(0, -1, disc, low, graph, size, result, returnSize);

    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}