#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
*/
/*
Method 1:
TC-O(N^2) SC-O(1) : Find next smaller and next smaller and use the two to find the required value.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> v;
        stack<pair<long long, long long>> st1, st2;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st1.empty() && st1.top().first >= arr[i])
                st1.pop();

            if (st1.empty())
                v.push_back(n);
            else
                v.push_back(st1.top().second);

            st1.push({arr[i], i});
        }

        reverse(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            while (!st2.empty() && st2.top().first >= arr[i])
                st2.pop();

            if (st2.empty())
                v[i] *= arr[i];
            else
            {
                v[i] -= (st2.top().second + 1);
                v[i] *= arr[i];
            }

            st2.push({arr[i], i});
        }

        return *max_element(v.begin(), v.end());
    }
};