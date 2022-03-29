#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1/

Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
*/
/*
Method 1:
TC-O(N^2) SC-O(N^2) :
*/
class Solution
{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                    dp[i][j] = matrix[i][j];
                else
                {
                    if (j == 0)
                        dp[i][j] = matrix[i][j] + max(dp[i - 1][j], dp[i - 1][j + 1]);

                    else if (j == n - 1)
                        dp[i][j] = matrix[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);

                    else
                        dp[i][j] = matrix[i][j] + max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1]));
                }
                if (i == n - 1)
                    res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};