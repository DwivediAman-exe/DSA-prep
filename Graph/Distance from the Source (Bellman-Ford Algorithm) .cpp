#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.
*/
/*
Method 1:
TC-O(V*E) SC-O(V) :
*/

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
    {
        vector<int> dist(V, 100000000);

        dist[S] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto y : adj)
            {
                if (dist[y[0]] + y[2] < dist[y[1]])
                    dist[y[1]] = dist[y[0]] + y[2];
            }
        }

        return dist;
    }
};