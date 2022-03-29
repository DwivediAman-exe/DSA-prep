#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/

Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
*/
/*
Method 1:
TC-O(N^2) SC-O(N) :
*/

class Solution
{
public:
    int cutRodUtil(int price[], int n, vector<int> &memo)
    {

        if (memo[n] != -1)
            return memo[n];

        int p = 0;

        for (int i = 1; i <= n; i++)
        {
            p = max(p, price[i - 1] + cutRodUtil(price, n - i, memo));
        }

        return memo[n] = p;
    }

    int cutRod(int price[], int n)
    {

        vector<int> memo(n + 1, -1);
        return cutRodUtil(price, n, memo);
    }
};

/*
Method 2:
TC-O(N^2) SC-O(N) :
*/

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }

        return dp[n];
    }
};