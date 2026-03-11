//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    int min = -10000, max = 10000;
    int range = max - min + 1;

    int freq[20001] = {0};

    for(int i = 0; i < n; i++)
        freq[nums[i] - min]++;

    for(int i = 0; i < k; i++) {
        int maxFreq = 0, idx = 0;

        for(int j = 0; j < range; j++) {
            if(freq[j] > maxFreq) {
                maxFreq = freq[j];
                idx = j;
            }
        }

        printf("%d ", idx + min);
        freq[idx] = 0;
    }

    return 0;
}
