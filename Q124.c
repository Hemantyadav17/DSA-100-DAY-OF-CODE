// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
//Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key. 
//When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, 
//and you can take all of them with you to unlock the other rooms. Given an array rooms where rooms[i] is the set of keys that you can 
//obtain if you visited room i, return true if you can visit all the rooms, or false otherwise

#include <stdio.h>

void dfs(int n, int rooms[n][1000], int size[], int visited[], int room) {
    visited[room] = 1;

    for (int i = 0; i < size[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(n, rooms, size, visited, key);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int rooms[n][1000];
    int size[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        scanf("%d", &size[i]);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    dfs(n, rooms, size, visited, 0);

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}