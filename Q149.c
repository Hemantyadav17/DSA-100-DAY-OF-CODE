// Problem Statement
//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum 
//is equal to zero.

#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0;
    int maxLen = 0;

    int map[2 * MAX];
    for (int i = 0; i < 2 * MAX; i++)
        map[i] = -2;

    map[MAX] = -1;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        if (map[prefix + MAX] != -2) {
            int len = i - map[prefix + MAX];
            if (len > maxLen)
                maxLen = len;
        } else {
            map[prefix + MAX] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}