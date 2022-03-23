#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.

*/
/*
Method 1:
TC-O(V+E) SC-O(V :
*/
class Solution
{
public:
    bool isCycleUtil(int node, vector<int> adj[], vector<bool> &vis, int parent)
    {
        vis[node] = true;

        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                if (isCycleUtil(i, adj, vis, node))
                    return true;
            }
            else if (i != parent)
            {
                return true;
            }
        }

        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleUtil(i, adj, vis, -1))
                    return true;
            }
        }

        return false;
    }
