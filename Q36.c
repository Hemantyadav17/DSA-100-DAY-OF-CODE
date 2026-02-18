//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//You must write an algorithm that runs in O(n) time and without using the division operation

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize)
{
    int* result = (int*)malloc(sizeof(int) * numsSize);

    int prefix = 1;
    for (int i = 0; i < numsSize; i++)
    {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int* result = productExceptSelf(nums, n);

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    free(result);
    return 0;
}