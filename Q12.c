//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

//Note that you must do this in-place without making a copy of the array.

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[k++] = nums[i];
        }
    }
    while (k < numsSize) {
        nums[k++] = 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
