#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/smaller-on-left20360700/1/

Given an array arr[ ] of N positive integers, the task is to find the greatest element on the left of every element in the array which is strictly smaller than itself, if this element does not exist for an index print "-1".


*/
/*
Method 1:
TC-O(N*Log(N)) SC-O(N) :
*/

vector<int> Smallestonleft(int arr[], int n)
{
    vector<int> res;

    set<int> st;

    for (int i = 0; i < n; i++)
    {
        auto it = st.lower_bound(arr[i]);
        if (it == st.begin())
        {
            res.push_back(-1);
        }
        else
            res.push_back(*(--it));

        st.insert(arr[i]);
    }

    return res;
}