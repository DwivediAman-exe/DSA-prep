#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/word-break1352/1#

Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango" }
A = "ilike"
Output:
1
*/
/*
Method 1:
*/
class Solution
{
public:
    int wordBreakUtil(string A, unordered_set<string> &st)
    {

        int n = A.length();
        if (!n)
            return 1;

        for (int i = 1; i <= n; i++)
        {
            if ((st.find(A.substr(0, i)) != st.end()) && (wordBreakUtil(A.substr(i, n), st)))
                return 1;
        }

        return 0;
    }

    int wordBreak(string A, vector<string> &B)
    {
        unordered_set<string> st(B.begin(), B.end());

        return wordBreakUtil(A, st);
    }
};
/*
Method 2:
TC-O(N^2) SC-O(N) :
*/

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B)
    {
        unordered_set<string> st(B.begin(), B.end());

        int n = A.length();

        vector<bool> dp(n, false);

        for (int i = 0; i <= n; i++)
        {
            if (dp[i] == false)
            {
                if (st.find(A.substr(0, i)) != st.end())
                    dp[i] = true;
            }

            if (dp[i])
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (!dp[j] && st.find(A.substr(i, j - i)) != st.end())
                        dp[j] = true;
                }
            }

            if (dp[n] == true)
                return true;
        }

        return dp[n];
    }
};