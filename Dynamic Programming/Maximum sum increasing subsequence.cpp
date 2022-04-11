#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order i.e. increasing subsequence.

Input: N = 5, arr[] = {1, 101, 2, 3, 100}
Output: 106
*/

/*
Method 1:
TC-O(N^2) SC-O(N) : Memoization
*/

class Solution
{

public:
    int maxSumISUtil(int arr[], int n, int &res, vector<int> &memo)
    {
        if (n < 0)
            return 0;

        if (memo[n] != -1)
            return memo[n];

        int curr = arr[n];

        for (int i = 0; i < n; i++)
        {
            int t = maxSumISUtil(arr, i, res, memo);

            if (arr[n] > arr[i] && t + arr[n] > curr)
                curr = t + arr[n];
        }

        res = max(curr, res);

        return memo[n] = curr;
    }

    int maxSumIS(int arr[], int n)
    {
        int res = INT_MIN;

        vector<int> memo(n, -1);

        maxSumISUtil(arr, n - 1, res, memo);

        return res;
    }
};
/*
Method 2:
TC-O(N^2) SC-O(N) : Tabulation
*/
class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        int dp[n], res = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && arr[i] + dp[j] > dp[i])
                    dp[i] = dp[j] + arr[i];
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};