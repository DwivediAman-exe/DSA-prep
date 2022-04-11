#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1#

Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note:
1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
2.  For large test cases, output value will be too large, return the answer MODULO 10^9+7

Input:
S = "abbc"
Output: 3
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    // s : given string
    // return the expected answer

    int fun(string &s)
    {
        int a = 0, b = 0, c = 0, n = s.length();
        int mod = 1000000007;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                a = (1 + (2 * a) % mod) % mod;
            else if (s[i] == 'b')
                b = (a + (2 * b) % mod) % mod;
            else if (s[i] == 'c')
                c = (b + (2 * c) % mod) % mod;
        }

        return c;
    }
};