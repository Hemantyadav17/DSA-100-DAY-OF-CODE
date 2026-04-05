//You are given an m x n grid where each cell can have one of three values:

//0 representing an empty cell,
//1 representing a fresh orange, or
//2 representing a rotten orange.
//Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.


#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int grid[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);

    int queue[100][2];
    int front = 0, rear = 0;

    int fresh = 0, time = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            if (grid[i][j] == 1)
                fresh++;
        }
    }

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < rear && fresh > 0) {
        int size = rear - front;
        time++;

        for (int i = 0; i < size; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                    fresh--;
                }
            }
        }
    }

    if (fresh > 0)
        printf("-1\n");
    else
        printf("%d\n", time);

    return 0;
}