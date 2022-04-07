#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/coin-change2448/1#

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
*/
/*
Method 1:
TC-O(N * M) SC-O(N * M) : Memoization
*/

class Solution
{
public:
    long long memo[1001][1001];

    Solution()
    {
        memset(memo, -1, sizeof(memo));
    }

    long long int count(int S[], int m, int n)
    {

        if ((n < 0) || (m == 0))
            return 0;

        if (memo[n][m] != -1)
            return memo[n][m];

        if (n == 0)
            return 1;

        return memo[n][m] = count(S, m, n - S[m - 1]) + count(S, m - 1, n);
    }
};

/*
Method 2:
TC-O(N * M) SC-O(N * M) : Tabulation
*/

class Solution
{
public:
    long long int count(int S[], int m, int n)
    {

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = 1;
                }
                else if (j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 0;

                    if (S[j - 1] <= i)
                        dp[i][j] += dp[i - S[j - 1]][j];
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};

/*
Method 3:
TC-O(N * M) SC-O(N ) : Tabulation
*/

class Solution
{
public:
    long long int count(int S[], int m, int n)
    {

        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        for (int j = 0; j < m; j++)
        {
            for (int i = S[j]; i <= n; i++)
            {
                dp[i] += dp[i - S[j]];
            }
        }

        return dp[n];
    }
};