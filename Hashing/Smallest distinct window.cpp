#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1

Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

Input : "AABBBCBBAC"
Output : 3
*/
/*
Method 1:
TC-O(N) SC-O(1) : Size of map will be at most 256.
*/

class Solution
{
public:
    string findSubString(string str)
    {
        unordered_map<char, int> mp;
        unordered_set<char> st(str.begin(), str.end());

        int start = 0, c = 0, k = st.size(), resL = 0, resR = str.length() - 1, minLen = INT_MAX;

        for (int i = 0; i < str.length(); i++)
        {
            mp[str[i]]++;

            if (mp[str[i]] == 1)
                c++;

            if (c == k)
            {
                while (start < i && mp[str[start]] > 1)
                {
                    mp[str[start]]--;
                    if (mp[str[start]] == 0)
                        mp.erase(str[start]);
                    start++;
                }

                int len = i - start + 1;

                if (minLen > len)
                {
                    resL = start;
                    resR = i;
                    minLen = len;
                }
            }
        }

        return str.substr(resL, resR - resL + 1);
    }
};