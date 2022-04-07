#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
*/
/*
Method 1:
TC-O(N^3) SC-O(N^2) : Memoization
*/
class Solution
{
public:
    int matrixMultiplicationUtil(int arr[], int l, int r, vector<vector<int>> &memo)
    {
        if (l == r)
            return 0;

        if (memo[l][r] != -1)
            return memo[l][r];

        int res = INT_MAX;

        for (int i = l; i < r; i++)
        {
            res = min(res,
                      matrixMultiplicationUtil(arr, l, i, memo) +
                          matrixMultiplicationUtil(arr, i + 1, r, memo) +
                          arr[l - 1] * arr[i] * arr[r]);
        }

        return memo[l][r] = res;
    }

    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return matrixMultiplicationUtil(arr, 1, n - 1, memo);
    }
};
/*
Method 2:
TC-O(N^3) SC-O(N^2) : Tabulation
*/

class Solution
{
public:
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int gap = 1; gap < n - 1; gap++)
        {
            for (int i = 1; i < n - gap; i++)
            {
                int j = i + gap;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
                }
            }
        }

        return dp[1][n - 1];
    }
};