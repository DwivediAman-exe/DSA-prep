#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/max-distance-between-same-elements/1/

Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Input
    n= 6
    arr = {1, 1, 2, 2, 2, 1}

Output
5
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
*/
class Solution
{
public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                    res = max(res, j - i);
            }
        }

        return res;
    }
};
/*
Method 2:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        unordered_map<int, int> mp;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) == mp.end())
                mp[arr[i]] = i;
            else
                res = max(res, i - mp[arr[i]]);
        }

        return res;
    }
};