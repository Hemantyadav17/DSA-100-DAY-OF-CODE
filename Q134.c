// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
//You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc(n * sizeof(int*));
    int* size = (int*)calloc(n, sizeof(int));
    int* indegree = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        adj[i] = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[b][size[b]++] = a;
        indegree[a]++;
    }

    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int result[n], count = 0;

    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < size[node]; i++) {
            int next = adj[node][i];
            indegree[next]--;

            if (indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    if (count != n) {
        printf("No valid ordering\n");
    } else {
        for (int i = 0; i < n; i++)
            printf("%d ", result[i]);
    }

    return 0;
}