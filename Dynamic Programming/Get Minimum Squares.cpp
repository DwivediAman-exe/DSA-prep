#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1#

Given a number N. Find the minimum number of squares of any number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).

Input: N = 100
Output: 1
*/
/*
Method 1:
TC-O(N * Log(N)) SC-O(N) :
*/

class Solution
{
public:
    int MinSquares(int n)
    {
        int x = sqrt(n);

        int res = INT_MAX;

        for (int i = 1; i <= x; i++)
        {
            if (n % (i * i) == 0)
                res = min(res, n / (i * i));
            else
                res = min(res, n / (i * i) + MinSquares(n % (i * i)));
        }

        return res;
    }
};

/*
Method 2:
TC-O(N * Log(N)) SC-O(N) :
*/

class Solution
{
public:
    vector<int> memo;

    Solution()
    {
        memo.resize(10001, -1);
    }

    int MinSquares(int n)
    {

        if (memo[n] != -1)
            return memo[n];

        int x = sqrt(n);

        int res = INT_MAX;

        for (int i = 1; i <= x; i++)
        {
            if ((n - (i * i)) == 0)
                res = 1;
            else
                res = min(res, 1 + MinSquares(n - (i * i)));
        }

        return memo[n] = res;
    }
};

/*
Method 3:
TC-O(N * Log(N)) SC-O(N) :
*/

class Solution
{
public:
    int MinSquares(int n)
    {

        vector<int> dp(n + 1, 0);

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {

            int x = sqrt(i);

            int res = INT_MAX;

            for (int j = 1; j <= x; j++)
            {
                if ((i - (j * j)) == 0)
                    res = 1;
                else
                    res = min(res, 1 + dp[i - (j * j)]);
            }

            dp[i] = res;
        }

        return dp[n];
    }
};