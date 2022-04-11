#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/

Given an array containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Input:
A[] = {2, 7, 6, 1, 4, 5}
K = 3
Output: 4
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;

        int s = 0, len = 0;

        for (int i = 0; i < n; i++)
        {
            s += arr[i];

            int rem = ((s % k) + k) % k;
            cout << s << ' ' << rem << '\n';

            if (rem == 0)
            {
                len = max(len, i + 1);
            }
            else if (mp.find(rem) != mp.end())
            {
                len = max(len, i - mp[rem]);
            }
            else
                mp[rem] = i;
        }

        return len;
    }
};