#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/merge-intervals/

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/
/*
Method 1:
TC-O(N^2) SC-O(1) : For each interval compare it with other intervals and if it overlapps , merge them and remove the other interval from the list.
*/

/*
Method 2:
TC-O(N * Log(N)) SC-O(N) :
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        stack<vector<int>> st;
        vector<vector<int>> res;

        st.push(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (st.top()[1] < intervals[i][0])
            {
                st.push(intervals[i]);
            }
            else if (st.top()[1] < intervals[i][1])
            {
                st.top()[1] = intervals[i][1];
            }
        }

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};

/*
Method 3:
TC-O(N * Log(N)) SC-O(1) :
*/
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (res[res.size() - 1][1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
            else if (res[res.size() - 1][1] < intervals[i][1])
            {
                res[res.size() - 1][1] = intervals[i][1];
            }
        }

        return res;
    }
};