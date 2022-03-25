#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/alien-dictionary/1/

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Input:
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
*/
/*
Method 1:
TC-O(N * |S| + K) SC-O(K) :
*/
class Solution
{
public:
    string topoSort(int V, vector<int> adj[])
    {
        queue<int> q;
        string res;
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

            res += node + 'a';

            for (auto i : adj[node])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        return res;
    }

    string findOrder(string dict[], int N, int K)
    {
        vector<int> graph[K];

        for (int i = 0; i < N - 1; i++)
        {
            string a = dict[i], b = dict[i + 1];
            for (int j = 0; j < min(a.length(), b.length()); j++)
            {
                if (a[j] != b[j])
                {
                    graph[a[j] - 'a'].push_back(b[j] - 'a');
                    break;
                }
            }
        }

        return topoSort(K, graph);
    }
};