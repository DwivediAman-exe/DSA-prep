#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/

Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Input:
S = "aabacbebebe", K = 3
Output: 7
*/
/*
Method 1:
TC-O(N^3) SC-O(1) :  Generate all substrings with the help of 2 loops and check if each matches the condition with help of one more loop.
        Can be improved to n^2 with help of hashing.
*/

/*
Method 2:
TC-O(N) SC-O(1) : The map will contain max 26 keys hence it can be considered as constant space.
*/
class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        unordered_map<int, int> mp;
        int start = 0, res = -1;

        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;

            if (mp.size() == k)
            {
                res = max(res, i - start + 1);
            }
            else if (mp.size() > k)
            {
                while (mp.size() > k && start < i)
                {
                    mp[s[start]]--;
                    if (mp[s[start]] == 0)
                        mp.erase(s[start]);
                    start++;
                }
            }
        }

        return res;
    }
};