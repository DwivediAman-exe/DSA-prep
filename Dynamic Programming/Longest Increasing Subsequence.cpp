#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/longest-increasing-subsequence/

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
*/
/*
Method 1: Memoization
TC-O(N^2) SC-O(N) :
*/
class Solution
{
public:
    int memo[2501];

    int lengthOfLISUtil(vector<int> &nums, int n, int &res)
    {
        if (n == 1)
            return 1;

        if (memo[n] != -1)
            return memo[n];

        int lis_n = 1;

        for (int i = 1; i < n; i++)
        {
            int lis_i = lengthOfLISUtil(nums, i, res);

            if (nums[i - 1] < nums[n - 1] && lis_i + 1 > lis_n)
                lis_n = lis_i + 1;
        }

        res = max(res, lis_n);

        return memo[n] = lis_n;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int res = 1;

        memset(memo, -1, sizeof(memo));

        lengthOfLISUtil(nums, nums.size(), res);

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
    int lengthOfLIS(vector<int> &nums)
    {
        int dp[2501], n = nums.size();

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = 1;
            for (int j = 1; j < i; j++)
            {
                if (nums[j - 1] < nums[i - 1] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }

        return *max_element(dp, dp + n + 1);
    }
};

/*
Method 3:
TC-O(N * Log(N)) SC-O(N) :
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> lis;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            auto k = lower_bound(lis.begin(), lis.end(), nums[i]);
            if (k == lis.end())
                lis.push_back(nums[i]);
            else
                *k = nums[i];
        }

        return lis.size();
    }
};

/*
Method 4:
Find LCS of the sequence and the sequence in sorted order.
*/