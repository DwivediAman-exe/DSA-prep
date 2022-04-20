#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453

Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10
*/
/*
Method 1:
TC-O(N^3) SC-O(1) : For each window of size 1 ... n calculate the required value with help of two loops.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    vector<int> smaller_element_to_right(int arr[], int n)
    {
        stack<pair<int, int>> s;
        vector<int> res;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!(s.size() == 0) && arr[i] <= s.top().first)
                s.pop();
            if (s.size() == 0)
            {
                res.push_back(n);
            }
            else if (s.top().first < arr[i])
            {
                res.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(res.begin(), res.end());

        return res;
    }

    vector<int> smaller_element_to_left(int arr[], int n)
    {
        stack<pair<int, int>> s;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            while (!(s.size() == 0) && arr[i] <= s.top().first)
                s.pop();
            if (s.size() == 0)
            {
                res.push_back(-1);
            }
            else if (s.top().first < arr[i])
            {
                res.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }

        return res;
    }

    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n)
    {
        vector<int> sleft, sright;
        vector<int> res(n, 0);

        sleft = smaller_element_to_left(arr, n);
        sright = smaller_element_to_right(arr, n);

        for (int i = 0; i < n; i++)
        {
            int len = sright[i] - sleft[i] - 1;
            res[len - 1] = max(res[len - 1], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--)
            res[i] = max(res[i], res[i + 1]);

        return res;
    }
};