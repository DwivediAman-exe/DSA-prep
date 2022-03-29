#include <bits/stdc++.h>
using namespace std;
/*
Question Link -

Given two strings. The task is to find the length of the longest common substring.

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
*/
/*
Method 1:
TC-O(N * M) SC-O(N * M) :
*/
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int res = 0;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (S1[i - 1] == S2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        res = max(res, dp[i][j]);
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
            }
        }

        return res;
    }
};
/*
Method 2:
TC-O(M * N) SC-O(M) :
*/
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int res = 0, row = 0;

        vector<vector<int>> dp(2, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[row][j] = 0;
                }
                else
                {
                    if (S1[i - 1] == S2[j - 1])
                    {
                        dp[row][j] = 1 + dp[1 - row][j - 1];
                        res = max(res, dp[row][j]);
                    }
                    else
                    {
                        dp[row][j] = 0;
                    }
                }
            }
            row = 1 - row;
        }

        return res;
    }
};