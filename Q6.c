// You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

#include <stdio.h>

int missingNum(int *arr, int size) {
    int x = 0;
    for (int i = 1; i <= size + 1; i++) {
        x ^= i;
    }
    for (int i = 0; i < size; i++) {
        x ^= arr[i];
    }
    return x;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", missingNum(arr, n));
    return 0;
}
