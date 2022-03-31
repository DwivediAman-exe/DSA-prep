#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/count-the-paths4332/1/

Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].

Input: edges = {{0,1},{0,3},{1,2},{3,2}},
n = 4, s = 0, d = 2
Output: 2
*/
/*
Method 1:
TC-O(2^N) SC-O(N + E) :
*/

class Solution
{
public:
    void dfs(int x, int d, vector<vector<int>> &edges, int &res)
    {
        if (x == d)
        {
            res++;
            return;
        }

        for (auto y : edges)
        {
            if (y[0] == x)
                dfs(y[1], d, edges, res);
        }
    }
    int possible_paths(vector<vector<int>> edges, int n, int s, int d)
    {
        int res = 0;

        dfs(s, d, edges, res);

        return res;
    }
};
