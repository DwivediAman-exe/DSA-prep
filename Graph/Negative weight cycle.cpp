#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1/

Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
*/
/*
Method 1:
TC-O(V*E) SC-O(V) :
*/
class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                int src = edges[j][0];
                int dest = edges[j][1];
                int wt = edges[j][2];

                if (dist[src] != INT_MAX && dist[src] + wt < dist[dest])
                {
                    dist[dest] = dist[src] + wt;
                }
            }
        }

        for (int j = 0; j < edges.size(); j++)
        {
            int src = edges[j][0];
            int dest = edges[j][1];
            int wt = edges[j][2];

            if (dist[src] != INT_MAX && dist[src] + wt < dist[dest])
            {
                return 1;
            }
        }

        return 0;
    }
};