#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/sum-of-lengths-of-non-overlapping-subarrays2237/1/

Given an array arr[] of N elements, the task is to find the maximum sum of lengths of all non-overlapping subarrays with K as the maximum element in the subarray.

Input: N = 9, K = 4
arr[] = {2, 1, 4, 9, 2, 3, 8, 3, 4}
Output: 5
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/

class Solution
{

public:
    int calculateMaxSumLength(int arr[], int n, int k)
    {
        int res = 0, curr = 0;
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > k)
            {
                if (flag == true)
                {
                    res += curr;
                }
                curr = 0;
                flag = false;
            }
            else if (arr[i] == k)
            {
                flag = true;
                curr++;
            }
            else
            {
                curr++;
            }
        }
        if (flag == true)
        {
            res += curr;
        }
        return res;
    }
};