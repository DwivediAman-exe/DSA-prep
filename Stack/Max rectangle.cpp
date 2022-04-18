#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/max-rectangle

Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
*/
/*
Method 1:
TC-O(N * M) SC-O(M) :
*/
class Solution
{
public:
    int getMaxArea(vector<int> arr)
    {
        int n = arr.size();
        vector<int> v;
        stack<pair<int, int>> st1, st2;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st1.empty() && st1.top().first >= arr[i])
                st1.pop();

            if (st1.empty())
                v.push_back(n);
            else
                v.push_back(st1.top().second);

            st1.push({arr[i], i});
        }

        reverse(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            while (!st2.empty() && st2.top().first >= arr[i])
                st2.pop();

            if (st2.empty())
                v[i] *= arr[i];
            else
            {
                v[i] -= (st2.top().second + 1);
                v[i] *= arr[i];
            }

            st2.push({arr[i], i});
        }

        return *max_element(v.begin(), v.end());
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        vector<int> p(m, 0);
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 0)
                    p[j] = 0;
                else
                    p[j] += 1;
            }

            res = max(res, getMaxArea(p));
        }

        return res;
    }
};
