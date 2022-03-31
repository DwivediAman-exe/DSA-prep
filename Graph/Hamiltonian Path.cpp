#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1/

A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once. Given an undirected graph  the task is to check if a Hamiltonian path is present in it or not.

Input:
N = 4, M = 4
Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }
Output:
1
*/
/*
Method 1:
TC-O(N!) SC-O(N+M) :
*/

class Solution
{
public:
    bool dfsUtil(int src, int count, int n, vector<int> adj[], vector<bool> &vis)
    {
        if (count == n)
            return true;

        vis[src] = true;

        for (auto y : adj[src])
        {
            if (!vis[y] && dfsUtil(y, count + 1, n, adj, vis))
            {
                return true;
            }
        }

        vis[src] = false;

        return false;
    }

    bool check(int N, int M, vector<vector<int>> Edges)
    {
        vector<int> adj[N + 1];

        for (auto x : Edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<bool> vis(N, false);

        for (int i = 1; i <= N; i++)
        {
            if (dfsUtil(i, 1, N, adj, vis))
                return true;
        }

        return false;
    }
};