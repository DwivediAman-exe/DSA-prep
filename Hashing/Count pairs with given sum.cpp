#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1/

Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
Use 2 for loops.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(k - arr[i]) != mp.end())
            {
                res += mp[k - arr[i]];
            }

            mp[arr[i]]++;
        }

        return res;
    }
};