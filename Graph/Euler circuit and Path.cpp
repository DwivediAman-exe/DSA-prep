#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1/

Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. The task is to find that there exists the Euler Path or circuit or none in given undirected graph with V vertices and adjacency list adj.

*/
/*
Method 1:
TC-O(V) SC-O(1) :
*/

class Solution
{
public:
    int isEularCircuit(int V, vector<int> adj[])
    {
        int odd = 0;
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() % 2 == 1)
                odd++;
        }
        if (odd == 0)
            return 2;
        else if (odd == 2)
            return 1;
        return 0;
    }
};