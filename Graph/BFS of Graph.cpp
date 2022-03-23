#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


*/
/*
Method 1:
TC-O(V+E) SC-O(V) :
*/
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> res;
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for (auto i : adj[node])
            {
                if (!vis[i])
                {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }

        return res;
    }
};