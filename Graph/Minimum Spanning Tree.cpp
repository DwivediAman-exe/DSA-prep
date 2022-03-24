#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/

Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
*/
/*
Method 1:
TC-O(E * log(V)) SC-O(V) :
*/
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> dist(v, INT_MAX);
        vector<bool> inMST(v, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto i : adj[u])
            {
                int v = i[0], wt = i[1];

                if (dist[v] > wt && !inMST[v])
                {
                    dist[v] = wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int res = 0;

        for (int i : dist)
        {
            res += i;
        }

        return res;
    }
};
/*
Method 2: Kruskal's Algo
TC-O(ElogV) SC-O(E + V) :
*/

class DSU
{

    vector<int> parent;
    vector<int> rank;

public:
    DSU(int V)
    {
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void stUnion(int x, int y)
    {
        int p_x = find(x);
        int p_y = find(y);

        if (x == y)
            return;

        if (rank[p_x] < rank[p_y])
        {
            parent[p_x] = p_y;
        }
        else if (rank[p_x] > rank[p_y])
        {
            parent[p_y] = p_x;
        }
        else // case of equality.
        {
            parent[p_y] = p_x;
            rank[p_x]++;
        }
    }
};

struct Edge
{
    int src, dest, wt;
    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }
};

bool mycomp(const Edge &a, const Edge &b)
{
    return a.wt < b.wt;
}

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DSU dset(V);
        vector<Edge> edges;
        int res = 0;

        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                Edge temp(i, j[0], j[1]);
                edges.push_back(temp);
            }
        }

        sort(edges.begin(), edges.end(), mycomp);

        for (int i = 0; i < edges.size(); i++)
        {
            if (dset.find(edges[i].src) != dset.find(edges[i].dest))
            {
                res += edges[i].wt;
                dset.stUnion(edges[i].src, edges[i].dest);
            }
        }

        return res;
    }
};