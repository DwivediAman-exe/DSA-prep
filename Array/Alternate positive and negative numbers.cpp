#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1/

Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with positive number.

Input:
    N = 9
    Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2

Method 1:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> pos;
        vector<int> neg;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                pos.push_back(arr[i]);
            }
            else
            {
                neg.push_back(arr[i]);
            }
        }

        int i = 0, j = 0, k = 0;

        while (k < n)
        {
            if (i < pos.size())
            {
                arr[k++] = pos[i++];
            }
            if (j < neg.size())
            {
                arr[k++] = neg[j++];
            }
        }
    }
};