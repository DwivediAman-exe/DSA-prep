#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1/

Given a sorted array, arr[] of N integers, and a value X. Find the K closest elements to X in arr[].
Keep the following points in mind:

If X is present in the array, then it need not be considered.
If there are two elements with the same difference with X, the greater element is given priority.
If sufficient elements are not present on the right side then take elements from left and vice versa.

Input:
N = 13
arr[] = {12, 16, 22, 30, 35, 39, 42,
         45, 48, 50, 53, 55, 56}
K = 4, X = 35
Output: 39 30 42 45

Method 1:
TC-O(logN + K) SC-O(1) :
*/

class Solution
{
public:
    int binary_search_floor(vector<int> arr, int n, int x)
    {
        int l = 0, r = n - 1, ans = 0;

        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (arr[m] <= x)
            {
                ans = max(ans, m);
            }
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }

        return ans;
    }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {

        int nearest = binary_search_floor(arr, n, x);
        int left, right;
        vector<int> res;

        if (arr[nearest] == x)
        {
            left = nearest - 1;
            right = nearest + 1;
        }
        else
        {
            left = nearest;
            right = nearest + 1;
        }

        while (left >= 0 && right < n && res.size() < k)
        {
            if (abs(arr[right] - x) <= abs(arr[left] - x))
            {
                res.push_back(arr[right++]);
            }
            else
            {
                res.push_back(arr[left--]);
            }
        }

        if (res.size() < k)
        {
            while (res.size() < k && right < n)
                res.push_back(arr[right++]);
            while (res.size() < k && left >= 0)
                res.push_back(arr[left--]);
        }
        return res;
    }
};