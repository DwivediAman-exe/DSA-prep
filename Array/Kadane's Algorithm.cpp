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
Method 2:   Divide and Conquer
TC-O(N*Log(N)) SC - O(1)
*/

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxCrossSubarraySum(int arr[], int l, int mid, int r)
    {
        long long leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;

        for (int i = mid; i >= l; i--)
        {
            sum += arr[i];
            if (sum > leftSum)
                leftSum = sum;
        }

        sum = 0;

        for (int i = mid + 1; i <= r; i++)
        {
            sum += arr[i];
            if (sum > rightSum)
                rightSum = sum;
        }

        return max({leftSum, rightSum, leftSum + rightSum});
    }
    long long maxSubarraySumUtil(int arr[], int l, int r)
    {
        if (l == r)
            return arr[l];

        int mid = l + (r - l) / 2;

        return max({maxSubarraySumUtil(arr, l, mid),
                    maxSubarraySumUtil(arr, mid + 1, r),
                    maxCrossSubarraySum(arr, l, mid, r)});
    }

    long long maxSubarraySum(int arr[], int n)
    {
        return maxSubarraySumUtil(arr, 0, n - 1);
    }
};

/*
Method 3:
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
