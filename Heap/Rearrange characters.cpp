#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1/

Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Input : str = "geeksforgeeks"
Output: 1
*/
/*
Method 1:
TC-O(N * Log(N)) SC-O(N) :
*/
class Solution
{
public:
    string rearrangeString(string str)
    {
        string res;
        unordered_map<int, int> mp;
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < str.length(); i++)
        {
            mp[str[i]]++;
        }

        for (auto i : mp)
        {
            pq.push({i.second, i.first});
        }

        pair<int, char> prev = {0, '#'};

        while (!pq.empty())
        {
            pair<int, char> temp = pq.top();
            pq.pop();

            res += temp.second;
            temp.first--;

            if (prev.first > 0)
            {
                pq.push(prev);
            }

            prev = temp;
        }

        if (res.length() != str.length())
            return "-1";

        return res;
    }
};