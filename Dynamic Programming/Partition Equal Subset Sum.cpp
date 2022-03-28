#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/partition-equal-subset-sum/

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Input: nums = [1,5,11,5]
Output: true
*/
/*
Method 1:
TC-O(N * Sum) SC-O( N * Sum) : Tabulation
*/
class Solution
{
public:
    bool canPartitionUtil(vector<int> arr, int sum)
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

    bool canPartition(vector<int> &nums)
    {
        int s = 0;

        for (int i = 0; i < nums.size(); i++)
            s += nums[i];

        if (s % 2)
            return false;
        else
            return canPartitionUtil(nums, s / 2);
    }
};