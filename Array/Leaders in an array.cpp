#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

Given an array A of positive integers. Your task is to find the leaders in the array.
An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.
Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2

Method 1:
TC - O(N*N) SC-(1)
*/
class Solution
{
public:
    vector<int> leaders(int arr[], int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] < arr[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(arr[i]);
        }
        return ans;
    }
};
/*
Method 2:
TC - O(N) SC-(1)
*/
class Solution
{
public:
    vector<int> leaders(int arr[], int n)
    {
        vector<int> ans;
        long long curr_lead = arr[n - 1];
        ans.push_back(arr[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= curr_lead)
            {
                curr_lead = arr[i];
                ans.push_back(curr_lead);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
