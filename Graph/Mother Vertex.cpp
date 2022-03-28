#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/mother-vertex/1/

Given a Directed Graph, find a Mother Vertex in the Graph (if present).
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
*/
/*
Method 1:
TC-O(V+E) SC-O(V) :
*/
class Solution
{
public:
    void dfsOfGraphUtil(int node, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = true;

        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                dfsOfGraphUtil(i, adj, vis);
            }
        }
    }

    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);

        int j;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsOfGraphUtil(i, adj, vis);
                j = i;
            }
        }

        for (int i = 0; i < V; i++)
            vis[i] = false;

        dfsOfGraphUtil(j, adj, vis);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                return -1;
        }

        return j;
    }
};