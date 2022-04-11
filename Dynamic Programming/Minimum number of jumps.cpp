#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.

Input:
N = 11
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3
*/
/*
Method 1:

TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        int curr = 0, res = 0, maxl = 0;
        for (int i = 0; i < n - 1; i++)
        {
            curr = max(curr, arr[i] + i);

            if (i == maxl)
            {
                maxl = curr;
                res++;
            }

            if (maxl >= n - 1)
                break;
        }
        if (maxl < n - 1)
            return -1;

        return res;
    }
};