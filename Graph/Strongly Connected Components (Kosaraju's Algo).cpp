#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

*/
/*
Method 1:
TC-O(V+E) SC-O(V) :
*/

class Solution
{
public:
    void dfsUtil(int node, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = true;

        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                dfsUtil(i, adj, vis);
            }
        }
    }

    void fillorder(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st)
    {
        vis[node] = true;

        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                fillorder(i, adj, vis, st);
            }
        }

        st.push(node);
    }

    // Function to return a list containing the DFS traversal of the graph.
    void dfsOfGraph(int V, vector<int> adj[], stack<int> &st, vector<bool> &vis)
    {
        for (int i = 0; i < V; i++)
            if (!vis[i])
                fillorder(i, adj, vis, st);
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> vis(V, false);
        dfsOfGraph(V, adj, st, vis);

        vector<int> adjt[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = false;
            for (int y : adj[i])
            {
                adjt[y].push_back(i);
            }
        }

        int res = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!vis[node])
            {
                res++;
                dfsUtil(node, adjt, vis);
            }
        }

        return res;
    }
};