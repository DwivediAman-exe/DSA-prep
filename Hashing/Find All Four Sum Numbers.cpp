#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1/

Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
*/
/*
Method 1:
TC-O(N^3) SC-O(N^2) :
*/
class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        vector<vector<int>> res;
        int n = arr.size();

        sort(arr.begin(), arr.end());
        unordered_map<int, pair<int, int>> mp;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                mp[arr[i] + arr[j]] = {i, j};
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int s = arr[i] + arr[j];

                if (mp.find(k - s) != mp.end())
                {
                    pair<int, int> p = mp[k - s];
                    if (i != p.first && j != p.second && j != p.first && i != p.second && i < p.first && j < p.second)
                    {
                        res.push_back({arr[i], arr[j], arr[p.first], arr[p.second]});
                    }
                }
            }
        }

        return res;
    }
};

/* To remove duplicate elements form final result we can also use while loops in each for loop to move the iterator forward while the elements are same.*/