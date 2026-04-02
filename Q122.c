// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, 
//and city b is connected directly with city c, then city a is connected indirectly with city c.
//A province is a group of directly or indirectly connected cities and no other cities outside of the group.
//You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise
//Return the total number of provinces.

 

#include <stdio.h>

void dfs(int n, int graph[n][n], int visited[], int city) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[city][i] == 1 && !visited[i]) {
            dfs(n, graph, visited, i);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[n][n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(n, graph, visited, i);
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}