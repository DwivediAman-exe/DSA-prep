#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1/

Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    int lenOfLongSubarr(int A[], int n, int k)
    {
        int s = 0, len = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            s += A[i];

            if (mp.find(s) == mp.end())
                mp[s] = i;
            if (mp.find(s - k) != mp.end())
            {
                len = max(len, i - mp[s - k]);
            }
        }
        return len;
    }
};