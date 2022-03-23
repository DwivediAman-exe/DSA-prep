#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

*/
/*
Method 1:
TC-O(V+E) SC-O(V) :
*/
class Solution
{
public:
    bool isCycleUtil(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &rec_stack)
    {
        vis[node] = true;
        rec_stack[node] = true;

        for (auto i : adj[node])
        {
            if (!vis[i] && isCycleUtil(i, adj, vis, rec_stack))
            {
                return true;
            }
            else if (rec_stack[i])
            {
                return true;
            }
        }

        rec_stack[node] = false;

        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<bool> rec_stack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && isCycleUtil(i, adj, vis, rec_stack))
                return true;
        }

        return false;
    }
};