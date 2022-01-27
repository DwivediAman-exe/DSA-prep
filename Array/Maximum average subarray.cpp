#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-average-subarray5859/1/

Given an array Arr of size N and a positive integer K, find the sub-array of length K with the maximum average.

Input:
K = 4, N = 6
Arr[] = {1, 12, -5, -6, 50, 3}
Output: 12 -5 -6 50
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    int findMaxAverage(int arr[], int n, int k)
    {
        int s = 0, start = 0, end = k - 1, res = 0;

        for (int i = 0; i < k; i++)
        {
            s += arr[i];
        }

        res = s;

        for (int i = k; i < n; i++)
        {
            s -= arr[i - k];
            s += arr[i];
            if (s > res)
            {
                res = s;
                end = i;
                start = i - k + 1;
            }
        }

        return start;
    }
};