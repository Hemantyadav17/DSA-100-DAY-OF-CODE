// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges
// times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel
// from source to target. We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive
// the signal. If it is impossible for all the n nodes to receive the signal, return -1.

#include <stdio.h>

#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n+1][n+1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int k;
    scanf("%d", &k);

    int dist[n+1], visited[n+1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[k] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1, min = INF;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            printf("-1\n");
            return 0;
        }
        if (dist[i] > ans) ans = dist[i];
    }

    printf("%d\n", ans);

    return 0;
}