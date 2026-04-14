// In this problem, a tree is an undirected graph that is connected and has no cycles.
//You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
//The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
//eturn an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 #include <stdio.h>
#include <stdlib.h>

int parent[1001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb)
        parent[pa] = pb;
}

int main() {
    int n;
    scanf("%d", &n);

    int edges[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int u = -1, v = -1;

    for (int i = 0; i < n; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        if (find(a) == find(b)) {
            u = a;
            v = b;
        } else {
            unionSet(a, b);
        }
    }

    printf("%d %d\n", u, v);

    return 0;
}