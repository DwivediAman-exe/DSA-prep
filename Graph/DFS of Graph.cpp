#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


*/
/*
Method 1:
TC-O(V+E) SC-O(V) :
*/
class Solution
{
public:
    void dfsOfGraphUtil(int node, vector<int> adj[], vector<bool> &vis, vector<int> &res)
    {
        vis[node] = true;
        res.push_back(node);

        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                dfsOfGraphUtil(i, adj, vis, res);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> res;
        vector<bool> vis(V);

        dfsOfGraphUtil(0, adj, vis, res);

        return res;
    }
};
