#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/minimum-swaps/1/

Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

Input:
nums = {2, 8, 5, 4}
Output:
1
*/
/*
Method 1:
TC-O(N * Log(N)) SC-O(N) :
*/
class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        vector<pair<int, int>> arr(nums.size());
        vector<bool> vis(nums.size(), false);
        int c = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;

            if (i == arr[i].second)
                vis[i] = true;

            while (!vis[j])
            {
                vis[j] = true;
                j = arr[j].second;
                if (!vis[j])
                    c++;
            }
        }

        return c;
    }
};
/*
Method 2:
TC-O(N * Log(N)) SC-O(N) :
*/
class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        vector<int> arr = nums;
        unordered_map<int, int> mp;
        int c = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (arr[i] != nums[i])
            {
                c++;
                int x = nums[i];
                swap(nums[i], nums[mp[arr[i]]]);

                mp[x] = mp[arr[i]];
                mp[arr[i]] = i;
            }
        }

        return c;
    }
};