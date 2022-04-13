#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1/#

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

Input:
S = "aaaabbaa"
Output:
aabbaa
*/
/*
Method 1:
TC-O(N^3) SC-O(1) : Check for each substring if it is a palindrome.
*/

/*
Method 2:
TC-O(N^2) SC-O(N^2) : DP
*/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length(), start = 0, maxLen = 1;

        bool dp[n][n] = {false};

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;

                if (maxLen < 2)
                {
                    start = i;
                    maxLen = 2;
                }
            }
        }

        for (int gap = 2; gap < n; gap++)
        {
            for (int i = 0; i < n - gap; i++)
            {
                int j = i + gap;

                if (dp[i + 1][j - 1] && s[i] == s[j])
                {
                    dp[i][j] = true;

                    if (maxLen < gap + 1)
                    {
                        start = i;
                        maxLen = gap + 1;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

/*
Method 3:
TC-O(N^2) SC-O(15) :
*/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length(), start = 0, maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            int high = i + 1, low = i - 1;

            while (high < n && s[i] == s[high])
                high++;

            while (low >= 0 && s[i] == s[low])
                low--;

            while (high < n && low >= 0 && s[high] == s[low])
            {
                high++;
                low--;
            }

            if (maxLen < high - low - 1)
            {
                start = low + 1;
                maxLen = high - low - 1;
            }
        }

        return s.substr(start, maxLen);
    }
};