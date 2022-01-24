#include <bits/stdc++.h>
using namespace std;
/*
Question link - https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1,
compute how much water can be trapped between the blocks during the rainy season.
Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

Method 1:
TC-O(N*N) SC-O(1)
*/
class Solution
{
public:
    long long trappingWater(int arr[], int n)
    {
        int res = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int lmax = arr[i]; // max element of left
            for (int j = 0; j < i; j++)
                lmax = max(lmax, arr[j]);

            int rmax = arr[i]; // max element of right
            for (int j = i + 1; j < n; j++)
                rmax = max(rmax, arr[j]);

            res = res + (min(lmax, rmax) - arr[i]);
        }
        return res;
    }
};
/*
Method 2:
TC-O(N)+O(N)+O(N) ~ O(3N) ~ O(N) SC-O(N)
*/
class Solution
{
public:
    long long trappingWater(int arr[], int n)
    {
        long long res = 0;
        long long lmax[n], rmax[n];

        lmax[0] = arr[0];
        for (int i = 1; i < n; i++)
            lmax[i] = max((long long)arr[i], lmax[i - 1]);

        rmax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rmax[i] = max((long long)arr[i], rmax[i + 1]);

        for (int i = 1; i < n - 1; i++)
            res = res + (min(lmax[i], rmax[i]) - arr[i]);

        return res;
    }
};
/*
Method 3:
TC-O(N) SC-O(1)
*/
class Solution
{
public:
    long long trappingWater(int arr[], int n)
    {
        long long res = 0;
        int high1 = 0, high2 = 0, l = 0, r = n - 1;
        while (l < r)
        {
            if (arr[l] < arr[r])
            {
                high1 = max(high1, arr[l]);
                res += high1 - arr[l++];
            }
            else
            {
                high2 = max(high2, arr[r]);
                res += high2 - arr[r--];
            }
        }
        return res;
    }
};
