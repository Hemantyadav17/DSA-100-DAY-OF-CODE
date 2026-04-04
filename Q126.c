//You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel
/// image[sr][sc].

#include <stdio.h>

void dfs(int m, int n, int image[m][n], int r, int c, int oldColor, int newColor) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(m, n, image, r+1, c, oldColor, newColor);
    dfs(m, n, image, r-1, c, oldColor, newColor);
    dfs(m, n, image, r, c+1, oldColor, newColor);
    dfs(m, n, image, r, c-1, oldColor, newColor);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int image[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &image[i][j]);

    int sr, sc, color;
    scanf("%d %d %d", &sr, &sc, &color);

    int oldColor = image[sr][sc];

    if (oldColor != color)
        dfs(m, n, image, sr, sc, oldColor, color);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", image[i][j]);
        printf("\n");
    }

    return 0;
}