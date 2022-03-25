#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1/

Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.
*/
/*
Method 1:
TC-O(V+E) SC-O(V) :
*/
class Solution
{
public:
    void dfsOfGraph(int node, vector<int> adj[], vector<bool> &vis, int &c, int &d)
    {
        vis[node] = true;

        for (auto i : adj[node])
        {
            if ((node == c && i == d) || (node == d && i == c))
                continue;
            if (!vis[i])
            {
                dfsOfGraph(i, adj, vis, c, d);
            }
        }
    }

    // Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        vector<bool> vis(V, false);
        dfsOfGraph(c, adj, vis, c, d);
        if (vis[d])
            return 0;
        return 1;
    }
};