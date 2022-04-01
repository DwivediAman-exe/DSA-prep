#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s

Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Input:
N = 4
A[] = {0,1,0,1}
Output: 4
*/
/*
Method 1:
TC-O(N^2) SC-O(1) : Generate all subarrays with 2 loops.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    int maxLen(int arr[], int N)
    {
        unordered_map<int, int> mp;
        int res = 0, s = 0;

        mp[0] = -1;

        for (int i = 0; i < N; i++)
        {
            s += (arr[i] == 0) ? -1 : 1;

            if (mp.find(s) == mp.end())
            {
                mp[s] = i;
            }
            else
            {
                res = max(res, i - mp[s]);
            }
        }

        return res;
    }
};