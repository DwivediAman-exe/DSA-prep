#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/bipartite-graph/1/

Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

*/
/*
Method 1:
TC-O(V+E) SC-O(V) :
*/
class Solution
{
public:
    bool isBipartiteUtil(int node, vector<int> adj[], vector<bool> &color, vector<bool> &vis, bool parentColor)
    {
        vis[node] = true;
        color[node] = !parentColor;

        for (auto i : adj[node])
        {
            if (!vis[i] && !isBipartiteUtil(i, adj, color, vis, color[node]))
            {
                return false;
            }
            else if (color[i] == color[node])
                return false;
        }

        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        vector<bool> color(V, false), vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && !isBipartiteUtil(i, adj, color, vis, true))
                return false;
        }

        return true;
    }
};