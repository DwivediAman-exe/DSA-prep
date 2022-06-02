#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/find-the-duplicate-number/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/
/*
Method 1:
TC-O(N^2) SC-O(1) : Brute Force
*/
/*
Method 2:
TC-O(N * Log(N)) SC-O(1) : Sorting
*/
/*
Method 3:
TC-O(N) SC-O(N) : Hashing
*/
/*
Method 4:
TC-O(N) SC-O(1) : Make value of arr[i] negative and keep checking for already negative value.
*/
/*
Method 5:
TC-O(N) SC-O(1) :  No modification in array.
*/
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        if (nums.size() <= 1)
            return -1;

        int slow = nums[0];
        int fast = nums[slow];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};