#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1/

Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.

Input:
    N = 3
    arr[] = {1, 0, 1}
    M = 1
Output:
3

Method 1:
TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m)
    {
        int s = 0, e = 0, no_0 = 0, res = 0;

        while (e < n)
        {
            if (arr[e] == 0)
                no_0++;

            while (no_0 > m)
            {
                if (arr[s] == 0)
                    no_0--;
                s++;
            }

            res = max(res, e - s + 1);
            e++;
        }

        return res;
    }
};