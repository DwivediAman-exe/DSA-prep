#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/

Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
*/
/*
Method 1:
TC-O(N * k * k) SC-O(1) : for every window of size k check for distinct numbers.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    vector<int> countDistinct(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;
        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            mp[arr[i]]++;
        }

        res.push_back(mp.size());

        for (int i = 1; i <= n - k; i++)
        {
            mp[arr[i - 1]]--;
            if (mp[arr[i - 1]] == 0)
            {
                mp.erase(arr[i - 1]);
            }
            mp[arr[i + k - 1]]++;

            res.push_back(mp.size());
        }

        return res;
    }
};