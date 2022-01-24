#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1

Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].
Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation:
arr[arr[0]] = arr[1] = 0
arr[arr[1]] = arr[0] = 1.

Method 1:
TC-O(N) SC-O(N)
*/
class Solution
{
public:
    void arrange(long long arr[], int n)
    {
        long long temp[n] = {};
        for (int i = 0; i < n; i++)
            temp[i] = arr[i];

        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[temp[i]];
        }
    }
};
/*
Method 2:
TC-O(N) SC-O(1)
*/
class Solution
{
public:
    void arrange(long long arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] + (arr[arr[i]] % n) * n;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] / n; // Old value is arr[i]%n , new value is arr[i]/n
        }
    }
};
/*
Explanation : Let’s assume an element is a and another element is b, both the elements are less than n. So if an element a is incremented by b*n. So the element becomes a + b*n so when a + b*n is divided by n then the value is b and a + b*n % n is a.
*/