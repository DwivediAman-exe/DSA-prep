#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#

You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Input:
N = 1, K = 2
Output: 2
*/
/*
Method 1:
TC-O(N * K^2) SC-O(N*K) :
*/

class Solution
{
public:
    int memo[201][201];

    Solution()
    {
        memset(memo, -1, sizeof(memo));
    }
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        if (k == 0 || k == 1)
            return k;

        if (n == 1)
            return k;

        if (memo[n][k] != -1)
            return memo[n][k];

        int curr, res = INT_MAX;

        for (int i = 1; i <= k; i++)
        {
            curr = max(eggDrop(n - 1, i - 1), eggDrop(n, k - i));
            res = min(res, curr);
        }

        return memo[n][k] = res + 1;
    }
};

/*
Method 2:
TC-O(N  * K^2) SC-O(N  * K) :
*/

class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        int dp[n + 1][k + 1] = {0};

        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = 1, dp[i][0] = 0;
        }

        for (int j = 1; j <= k; j++)
            dp[1][j] = j;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= k; j++)
            {

                int res = INT_MAX, curr;
                for (int x = 1; x <= j; x++)
                {
                    curr = max(dp[i - 1][x - 1], dp[i][j - x]);
                    res = min(res, curr);
                }

                dp[i][j] = 1 + res;
            }
        }

        return dp[n][k];
    }
};