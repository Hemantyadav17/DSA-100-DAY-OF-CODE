//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

//A circular array means the end of the array connects to the beginning of the array.
// Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

//A subarray may only include each element of the fixed buffer nums at most once.
// Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

#include <stdio.h>

int maxSubarraySumCircular(int* nums, int numsSize)
{
    int total = nums[0];
    int maxSum = nums[0], curMax = nums[0];
    int minSum = nums[0], curMin = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (curMax < 0)
            curMax = nums[i];
        else
            curMax += nums[i];

        if (curMin > 0)
            curMin = nums[i];
        else
            curMin += nums[i];

        if (curMax > maxSum)
            maxSum = curMax;

        if (curMin < minSum)
            minSum = curMin;

        total += nums[i];
    }

    if (maxSum < 0)
        return maxSum;

    if (total - minSum > maxSum)
        return total - minSum;

    return maxSum;
}

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int result = maxSubarraySumCircular(nums, n);
    printf("%d", result);

    return 0;
}