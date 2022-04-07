#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/

Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.

Input:
S = "timetopractice"
P = "toc"
Output:
toprac
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
*/
class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        string res;
        int len = s.length(), start = 0, sindex = -1, c = 0;

        if (s.length() < p.length())
            return "-1";

        int mp_pat[256] = {0}, mp_str[256] = {0};

        for (int i = 0; i < p.length(); i++)
        {
            mp_pat[p[i]]++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            mp_str[s[i]]++;

            if (mp_str[s[i]] <= mp_pat[s[i]])
                c++;

            if (c == p.length())
            {
                while (mp_str[s[start]] > mp_pat[s[start]])
                {
                    if (mp_pat[s[start]] < mp_str[s[start]])
                        mp_str[s[start]]--;

                    start++;
                }

                int clen = i - start + 1;

                if (clen < len)
                {
                    sindex = start;
                    len = clen;
                    // cout<<res<<' ';
                }
            }
        }
        if (sindex == -1)
            return "-1";
        return s.substr(sindex, len);
    }
};
/*
Method 2:
TC-O(N) SC-O(N) :
*/