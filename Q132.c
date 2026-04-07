// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.


#include <stdio.h>
#include <stdlib.h>

int dfs(int** adj, int* size, int* vis, int* path, int node) {
    vis[node] = 1;
    path[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int next = adj[node][i];

        if (!vis[next]) {
            if (dfs(adj, size, vis, path, next))
                return 1;
        }
        else if (path[next]) {
            return 1;
        }
    }

    path[node] = 0;
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc(n * sizeof(int*));
    int* size = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        size[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[b][size[b]++] = a;
    }

    int vis[n], path[n];

    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        path[i] = 0;
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(adj, size, vis, path, i)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("false\n");
    else
        printf("true\n");

    return 0;
}