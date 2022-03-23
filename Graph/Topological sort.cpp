#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/topological-sort/1/

Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

*/
/*
Method 1:
TC-O(V+E) SC-O(V) : DFS
*/
class Solution
{
public:
    void topoSortUtil(int node, vector<int> adj[], stack<int> &st, vector<bool> &vis)
    {
        vis[node] = true;

        for (auto i : adj[node])
        {
            if (!vis[i])
                topoSortUtil(i, adj, st, vis);
        }

        st.push(node);
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> res;
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                topoSortUtil(i, adj, st, vis);
        }

        while (!st.empty())
        {
            int temp = st.top();
            st.pop();
            res.push_back(temp);
        }

        return res;
    }
};

/*
Method 2:
TC-O(V+E) SC-O(V) : Kahn's Method
*/

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> res;
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                indegree[j]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for (auto i : adj[node])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        return res;
    }
};