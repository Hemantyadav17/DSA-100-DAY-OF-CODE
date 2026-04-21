// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional
// and weighted edge between cities fromi and toi, and given the integer distanceThreshold. Return the city with the smallest number of 
//cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return
// the city with the greatest number. Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

#include <stdio.h>

#define INF 1000000000

// Simple Dijkstra (no priority queue)
void dijkstra(int n, int graph[n][n], int src, int dist[]) {
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        // Find minimum distance unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = 1;

        // Relax neighbors
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int findTheCity_Dijkstra(int n, int edges[][3], int edgesSize, int distanceThreshold) {
    int graph[n][n];

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    // Fill edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int minCount = INF, result = -1;

    // Run Dijkstra for each city
    for (int i = 0; i < n; i++) {
        int dist[n];
        dijkstra(n, graph, i, dist);

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[j] <= distanceThreshold)
                count++;
        }

        if (count <= minCount) {
            minCount = count;
            result = i;
        }
    }

    return result;
}