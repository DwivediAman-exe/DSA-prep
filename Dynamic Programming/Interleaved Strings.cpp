#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/interleaved-strings/1/#

Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

An interleaving of two strings S and T is a configuration such that it creates a new string Y from the concatenation substrings of A and B and |Y| = |A + B| = |C|

For example:

A = "XYZ"

B = "ABC"

so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you can create a string Y which can be equal to C.

Specifically, you just need to create substrings of string A and create substrings B and concatenate them and check whether it is equal to C or not.

Note: a + b is the concatenation of strings a and b.

Return true if C is formed by an interleaving of A and B, else return false.

Input:
A = YX, B = X, C = XXY
Output: 0
*/
/*
Method 1:
TC-O(N * M) SC-O(N * M) :
*/
class Solution
{
public:
    int memo[201][201];

    Solution()
    {
        memset(memo, -1, sizeof(memo));
    }

    bool isInterleaveUtil(string A, string B, string C, int n, int m)
    {
        if (n == 0 && m == 0)
            return true;

        int k = n + m;

        if (memo[n][m] != -1)
            return memo[n][m];

        bool res = false;

        if (n != 0 && C[k - 1] == A[n - 1])
        {
            res |= isInterleaveUtil(A, B, C, n - 1, m);
        }

        if (m != 0 && C[k - 1] == B[m - 1])
        {
            res |= isInterleaveUtil(A, B, C, n, m - 1);
        }

        return memo[n][m] = res;
    }

    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C)
    {
        int n = A.length(), m = B.length(), k = C.length();

        if (n + m != k)
            return false;

        return isInterleaveUtil(A, B, C, n, m);
    }
};
/*
Method 2:
TC-O(N*M) SC-O(N*M) :
*/

class Solution
{
public:
    bool isInterleave(string A, string B, string C)
    {
        int n = A.length(), m = B.length(), k = C.length();

        if (n + m != k)
            return false;

        bool dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                int k = i + j;

                bool res = false;
                dp[i][j] = false;

                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else
                {

                    if (i != 0 && C[k - 1] == A[i - 1])
                    {
                        res |= dp[i - 1][j];
                    }
                    if (j != 0 && C[k - 1] == B[j - 1])
                    {
                        res |= dp[i][j - 1];
                    }

                    dp[i][j] |= res;
                }
            }
        }

        return dp[n][m];
    }
};