#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/dice-throw5349/1#

Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.

Input:
M = 6, N = 3, X = 12
Output:
25
*/
/*
Method 1:
TC-O(M*N*X) SC-O(N*X) :
*/
class Solution
{
public:
    long long noOfWaysUtil(int M, int N, int X, vector<vector<long long>> &memo)
    {

        if (X == 0 && N == 0)
            return 1;
        if ((N == 0) || (X < 0))
            return 0;

        if (memo[N][X] != -1)
            return memo[N][X];

        long long res = 0;

        for (int i = 1; i <= M; i++)
        {
            res += noOfWaysUtil(M, N - 1, X - i, memo);
        }

        return memo[N][X] = res;
    }

    long long noOfWays(int M, int N, int X)
    {

        vector<vector<long long>> memo(N + 1, vector<long long>(X + 1, -1));

        return noOfWaysUtil(M, N, X, memo);
    }
};
/*
Method 2:
TC-O(M*N*X) SC-O(N*X) :
*/
class Solution
{
public:
    long long noOfWays(int M, int N, int X)
    {

        vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= X; j++)
            {
                for (int k = 1; k <= M; k++)
                {
                    if (j >= k)
                    {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }

        return dp[N][X];
    }
};