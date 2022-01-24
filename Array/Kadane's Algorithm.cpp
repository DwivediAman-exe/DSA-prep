#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1/

Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number)
which has the maximum sum and return its sum.
Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

Method 1:
TC-O(N*N) SC-O(1)
*/
class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {
        long long res = arr[0];
        for (int i = 0; i < n; i++)
        {
            long long curr = 0;
            for (int j = i; j < n; j++)
            {
                curr += arr[j];
                res = max(res, curr);
            }
        }
        return res;
    }
};
/*
Method 2:
TC-O(N) SC-O(1)
*/
class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {
        long long res = INT_MIN;
        long long curr_sum = 0;
        for (int i = 0; i < n; i++)
        {
            curr_sum += arr[i];
            res = max(res, curr_sum);
            if (curr_sum < 0)
                curr_sum = 0;
        }
        return res;
    }
};