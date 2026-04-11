// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei]
// indicates that there is a flight from city fromi to city toi with cost pricei.
//You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

#include <stdio.h>

#define INF 1000000000

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edges[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src, dst, k;
    scanf("%d %d %d", &src, &dst, &k);

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        int temp[n];

        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    if (dist[dst] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[dst]);

    return 0;
}
 

