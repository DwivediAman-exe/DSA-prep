#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1/#

You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
*/
/*
Method 1:
TC-O(N^2) SC-O(N^2) : Memoization
*/
// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    long long maximumAmountUtil(int arr[], int i, int j, vector<vector<int>> &memo)
    {
        if (i > j)
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        return memo[i][j] = max(
                   arr[i] + min(maximumAmountUtil(arr, i + 2, j, memo), maximumAmountUtil(arr, i + 1, j - 1, memo)),
                   arr[j] + min(maximumAmountUtil(arr, i + 1, j - 1, memo), maximumAmountUtil(arr, i, j - 2, memo)));
    }

    long long maximumAmount(int arr[], int n)
    {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

        return maximumAmountUtil(arr, 0, n - 1, memo);
    }
};
/*
Method 2:
TC-O(N^2) SC-O(N^2) : Tabulation
*/
// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    long long maximumAmount(int arr[], int n)
    {
        int dp[n][n];

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                int x = 0, y = 0, z = 0;

                if (i + 2 <= j)
                    x = dp[i + 2][j]; // else x = 0

                if (i + 1 <= j - 1)
                    y = dp[i + 1][j - 1];
                if (i <= j - 2)
                    z = dp[i][j - 2];

                dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
            }
        }

        return dp[0][n - 1];
    }
};