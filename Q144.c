// Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. 
//Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly 
//once and then at the end come back to city 0 at minimum cost.

#include <stdio.h>
#include <string.h>

#define MAX 16
#define INF 1000000000

int n;
int cost[MAX][MAX];
int dp[MAX][1 << MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] +
                         solve(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[pos][mask] = ans;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    memset(dp, -1, sizeof(dp));

    printf("%d\n", solve(1, 0));

    return 0;
}