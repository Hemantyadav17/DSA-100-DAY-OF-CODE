// Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include <stdio.h>

int maxSubArray(int* nums, int numsSize)
{
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (currentSum < 0)
            currentSum = nums[i];
        else
            currentSum += nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int result = maxSubArray(nums, n);
    printf("%d", result);

    return 0;
}