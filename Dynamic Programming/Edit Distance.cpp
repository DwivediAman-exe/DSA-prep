#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/edit-distance/

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3
*/
/*
Method 1:
TC-O(N * M) SC-O(N * M) : Memoization
*/
class Solution
{
public:
    int minDistanceUtil(string &word1, string &word2, int n, int m, vector<vector<int>> &memo)
    {
        if (n == 0 && m == 0)
            return 0;

        if (n == 0)
            return m;
        else if (m == 0)
            return n;

        if (memo[n][m] != -1)
            return memo[n][m];

        if (word1[n - 1] == word2[m - 1])
        {
            return memo[n][m] = minDistanceUtil(word1, word2, n - 1, m - 1, memo);
        }
        else
            return memo[n][m] = 1 + min({
                                        minDistanceUtil(word1, word2, n - 1, m, memo),
                                        minDistanceUtil(word1, word2, n, m - 1, memo),
                                        minDistanceUtil(word1, word2, n - 1, m - 1, memo),
                                    });
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        return minDistanceUtil(word1, word2, n, m, memo);
    }
};
/*
Method 2:
TC-O(N * M) SC-O(N * M) : Tabulation
*/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        int dp[501][501] = {0};

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else
                {
                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
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
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        int dp[2][501] = {0}, row = 1;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0)
                    dp[row][j] = j;
                else if (j == 0)
                    dp[row][j] = i;
                else
                {
                    if (word1[i - 1] == word2[j - 1])
                        dp[row][j] = dp[1 - row][j - 1];
                    else
                        dp[row][j] = 1 + min({dp[1 - row][j], dp[row][j - 1], dp[1 - row][j - 1]});
                }
            }
            row = 1 - row;
        }

        return dp[1 - row][m];
    }
};

/*
Method 4:
TC-O(N * M) SC-O(M) : Tabulation (Space Optimized) (1 X M)
*/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        int dp[501] = {0}, prev = 0;

        for (int i = 0; i <= n; i++)
        {
            prev = dp[0];

            for (int j = 0; j <= m; j++)
            {
                int temp = dp[j];

                if (i == 0)
                    dp[j] = j;
                else if (j == 0)
                    dp[j] = i;
                else
                {
                    if (word1[i - 1] == word2[j - 1])
                        dp[j] = prev;
                    else
                        dp[j] = 1 + min({dp[j], dp[j - 1], prev});
                }

                prev = temp;
            }
        }

        return dp[m];
    }
};