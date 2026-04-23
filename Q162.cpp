// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

#include <iostream>
using namespace std;

int main() {
    int n, target;

    // Input size
    cin >> n;

    int nums[n];

    // Input array
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input target
    cin >> target;

    int left = 0, right = n - 1;

    // Binary Search
    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(nums[mid] == target) {
            cout << mid;
            return 0;
        }
        else if(nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // If not found
    cout << -1;

    return 0;
}