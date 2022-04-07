#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#

Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

Input: N = 4, arr[] = {1, 6, 11, 5}
Output: 1
*/
/*
Method 1:
TC-O(N * Sum) SC-O(N * Sum) :
*/
class Solution
{

public:
    int minDifferenceUtil(int arr[], int n, int sum, int sumcalc, vector<vector<int>> &memo)
    {
        if (n == 0)
        {
            return abs(sum - 2 * sumcalc);
        }

        if (memo[n][sumcalc] != -1)
            return memo[n][sumcalc];

        return memo[n][sumcalc] = min(
                   minDifferenceUtil(arr, n - 1, sum, sumcalc + arr[n - 1], memo),
                   minDifferenceUtil(arr, n - 1, sum, sumcalc, memo));
    }

    int minDifference(int arr[], int n)
    {
        int s = 0;

        for (int i = 0; i < n; i++)
            s += arr[i];

        vector<vector<int>> memo(n + 1, vector<int>(s + 1, -1));
        return minDifferenceUtil(arr, n, s, 0, memo);
    }
};
/*
Method 2:
TC-O(N) SC-O(N) :
*/