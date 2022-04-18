#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101

Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output:
3 3 4 5 5 5 6
*/
/*
Method 1:
TC-O(N * k) SC-O(1) :  for every element of array run a for loop of k and find the maximum.
*/

/*
Method 2:
TC-O(N) SC-O(k) :
*/
class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && arr[dq.back()] < arr[i])
                dq.pop_back();
            dq.push_back(i);
        }

        for (int i = k; i < n; i++)
        {
            res.push_back(arr[dq.front()]);

            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && arr[dq.back()] < arr[i])
                dq.pop_back();

            dq.push_back(i);
        }

        res.push_back(arr[dq.front()]);

        return res;
    }
};