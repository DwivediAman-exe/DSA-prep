#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1/

Given an array arr[] of size n, find the first repeating element. The element should occurs more than once and the index of its first occurrence should be the smallest.

Input:
n = 7
arr[] = {1, 5, 3, 4, 3, 5, 6}
Output: 2
*/
/*
Method 1:
TC-O(N^2) SC-O(1) : Use 2 for loops.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {
        unordered_map<int, int> mp;
        int res = -1, resIndex = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = i;
            }
            else
            {
                if (mp[arr[i]] < resIndex)
                {
                    resIndex = mp[arr[i]];
                    res = arr[i];
                }
            }
        }

        return resIndex == INT_MAX ? -1 : resIndex + 1;
    }
};