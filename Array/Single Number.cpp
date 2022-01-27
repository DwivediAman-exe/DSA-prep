#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/single-number1014/1/

Given an array Arr of positive integers of size N where every element appears even times except for one. Find that number occuring odd number of times.

Input:
N = 5
Arr[] = {1, 1, 2, 2, 2}
Output: 2
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    int getSingle(int arr[], int n)
    {

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            res ^= arr[i];
        }

        return res;
    }
};

// Even times xor of some number is 0 and odd times xor of some number is the number itself.