#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/longest-common-subsequence/

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Input: text1 = "abcde", text2 = "ace"
Output: 3
*/
/*
Method 1:
TC-O(N * M) SC-O(N * M) : Memoization
*/
class Solution
{
public:
    int lcsUtil(string &text1, string &text2, int n, int m, int memo[][1001])
    {
        if (n == 0 || m == 0)
            return 0;

        if (memo[n][m] != -1)
            return memo[n][m];

        if (text1[n - 1] == text2[m - 1])
        {
            return memo[n][m] = 1 + lcsUtil(text1, text2, n - 1, m - 1, memo);
        }
        else
            return memo[n][m] = max(lcsUtil(text1, text2, n, m - 1, memo), lcsUtil(text1, text2, n - 1, m, memo));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();

        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));

        return lcsUtil(text1, text2, n, m, memo);
    }
};
/*
Method 2:
TC-O(N * M) SC-O(N * M) : Tabulation
*/
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();

        int dp[1001][1001] = {0};

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};

/*
Method 3:
TC-O(N * M) SC-O(M) : Tabulation (Space Optimized) (2 X M)
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();

        int dp[2][1001] = {0};
        int row = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[row][j] = 1 + dp[1 - row][j - 1];
                else
                    dp[row][j] = max(dp[1 - row][j], dp[row][j - 1]);
            }
            row = 1 - row;
        }

        return dp[1 - row][m];
    }
};

/*
Method 3:
TC-O(N * M) SC-O(M) : Tabulation (Space Optimized) (1 X M)
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();

        int dp[1001] = {0};
        int prev = 0;

        for (int i = 1; i <= n; i++)
        {
            prev = 0;
            for (int j = 1; j <= m; j++)
            {
                int temp = dp[j];

                if (text1[i - 1] == text2[j - 1])
                    dp[j] = 1 + prev;
                else
                    dp[j] = max(dp[j], dp[j - 1]);

                prev = temp;
            }
        }

        return dp[m];
    }
};