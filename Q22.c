//Given a 2D integer array matrix, return the transpose of matrix.
//The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}