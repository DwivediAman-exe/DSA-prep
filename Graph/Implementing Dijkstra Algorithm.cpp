#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/

Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.
*/
/*
Method 1:
TC-O(V^2) SC-O(V^2) :
Normal implementation requires a boolean array to mark if a vertex is already visited or not. In each iteration we find an unvisted node with minimum distance.
*/

/*
Method 2:
TC-O(ELogV) SC-O(V) :
*/
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st;

        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty())
        {
            pair<int, int> temp = *(st.begin());
            st.erase(st.begin());

            int u = temp.second;

            for (auto v : adj[u])
            {
                int wt = v[1];

                if (dist[v[0]] > dist[u] + wt)
                {
                    if (dist[v[0]] != INT_MAX)
                    {
                        st.erase({dist[v[0]], v[0]});
                    }

                    dist[v[0]] = dist[u] + wt;

                    st.insert({dist[v[0]], v[0]});
                }
            }
        }

        return dist;
    }
};

/* Similar solution can be written with the help of priority queue. A boolean array to mark if a vertex is visited or not is required.*/

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int> dist(v, INT_MAX);
        vector<bool> path(v, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        dist[s] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            path[u] = true;
            for (auto i : adj[u])
            {
                if (dist[i[0]] > dist[u] + i[1] && !path[i[0]])
                {
                    dist[i[0]] = dist[u] + i[1];
                    pq.push({dist[u] + i[1], i[0]});
                }
            }
        }
        return dist;
    }
};