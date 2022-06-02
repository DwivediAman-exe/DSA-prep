#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/total-decoding-messages1235

A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Input: str = "123"
Output: 3
*/
/*
Method 1:
TC-O(N) SC-O(N) : Memoization
*/

class Solution
{
public:
    int mod = 1000000007;
    int CountWaysUtil(string str, int i, vector<int> &memo)
    {
        if (str.size() == i)
            return 1;
        if (str[i] == '0')
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int ans = 0;
        if (str[i] >= '1' && str[i] <= '9')
            ans += CountWaysUtil(str, i + 1, memo);
        ans = ans % mod;

        if (i + 1 < str.size() && (str[i] == '1' || (str[i] == '2' && str[i + 1] <= '6')))
            ans += CountWaysUtil(str, i + 2, memo);
        ans = ans % mod;

        return memo[i] = ans % mod;
    }

    int CountWays(string str)
    {
        vector<int> memo(str.length(), -1);

        return CountWaysUtil(str, 0, memo);
    }
};

/*
Method 2:
TC-O(N) SC-O(N) : Tabulation
*/

class Solution
{
public:
    int mod = 1000000007;

    int CountWays(string str)
    {
        int n = str.length();
        vector<int> dp(n + 1, 0);

        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (str[i] == '0')
            {
                dp[i] = 0;
                continue;
            }
            if (str[i] >= '1' && str[i] <= '9')
                dp[i] = (dp[i] + dp[i + 1]) % mod;
            if (i + 1 < str.size() && (str[i] == '1' || (str[i] == '2' && str[i + 1] <= '6')))
                dp[i] = (dp[i] + dp[i + 2]) % mod;
        }
        return dp[0] % mod;
    }
};