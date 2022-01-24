#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/

Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

Input:
    N = 5
    A[] = {1,2,1,1,3}
Output: 1

*/
/*
Method 1:
TC-O(N^3) SC-O(1) :
Run 3 loops and check if there are 3 numbers that satisfy this condition.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int n)
    {
        vector<int> smallest_left(n), greatest_right(n);

        int mn = INT_MAX, mx = INT_MIN;

        for (int i = 0; i < n - 1; i++)
        {
            mn = min(mn, arr[i]);
            smallest_left[i + 1] = mn;
        }

        for (int i = n - 1; i > 0; i--)
        {
            mx = max(mx, arr[i]);
            greatest_right[i - 1] = mx;
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (smallest_left[i] < arr[i] && greatest_right[i] > arr[i])
                return {smallest_left[i], arr[i], greatest_right[i]};
        }

        return {};
    }
};