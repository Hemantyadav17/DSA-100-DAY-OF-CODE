//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 
#include <stdio.h>

void reverse(int* arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

int main()
{
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    rotate(nums, n, k);

    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
