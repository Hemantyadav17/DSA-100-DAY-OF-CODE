// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int points[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int dist[n], visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0;
    int cost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;
        cost += min;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int d = abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]);

                if (d < dist[v])
                    dist[v] = d;
            }
        }
    }

    printf("%d\n", cost);

    return 0;
} 

