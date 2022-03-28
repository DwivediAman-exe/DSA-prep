#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1
*/
/*
Method 1:
TC-O(N * Sum) SC-O(N * Sum) :
*/
class Solution
{
public:
    int isSubsetSumUtil(vector<int> arr, int sum, int n, vector<vector<int>> &memo)
    {
        if (sum == 0)
            return 1;

        if (n <= 0)
            return 0;

        if (memo[n - 1][sum] != -1)
            return memo[n - 1][sum];

        if (sum < arr[n - 1])
            return memo[n - 1][sum] = isSubsetSumUtil(arr, sum, n - 1, memo);

        return memo[n - 1][sum] = isSubsetSumUtil(arr, sum - arr[n - 1], n - 1, memo) || isSubsetSumUtil(arr, sum, n - 1, memo);
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));

        isSubsetSumUtil(arr, sum, n, memo);

        return memo[n - 1][sum];
    }
};
/*
Method 2:
TC-O(N * Sum) SC-O(N * Sum) :
*/
class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else
                {
                    if (arr[i - 1] > j)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};
/*
Method 3:
TC-O(N * Sum) SC-O(Sum) :
*/

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(2, vector<bool>(sum + 1, 0));
        int row = 0;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0)
                    dp[row][j] = true;
                else if (i == 0)
                    dp[row][j] = false;
                else
                {
                    if (arr[i - 1] > j)
                        dp[row][j] = dp[1 - row][j];
                    else
                        dp[row][j] = dp[1 - row][j] || dp[1 - row][j - arr[i - 1]];
                }
            }
            row = 1 - row;
        }

        return dp[1 - row][sum];
    }
};