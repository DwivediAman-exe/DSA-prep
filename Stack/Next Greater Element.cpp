#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/

Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Input:
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
*/
/*
Method 1:
TC-O(N^2) SC-O(1) : Use 2 loops.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> st;
        vector<long long> res;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();

            if (st.empty())
            {
                res.push_back(-1);
            }
            else
                res.push_back(st.top());

            st.push(arr[i]);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};