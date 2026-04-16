// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, 
//where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:\


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int graph[n][n];
    int size[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = -1;

    int queue[1000];

    for (int i = 0; i < n; i++) {
        if (color[i] != -1) continue;

        int front = 0, rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int j = 0; j < size[node]; j++) {
                int adj = graph[node][j];

                if (color[adj] == -1) {
                    color[adj] = 1 - color[node];
                    queue[rear++] = adj;
                }
                else if (color[adj] == color[node]) {
                    printf("false\n");
                    return 0;
                }
            }
        }
    }

    printf("true\n");
    return 0;
}