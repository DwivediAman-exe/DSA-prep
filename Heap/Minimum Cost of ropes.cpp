#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Input:
    n = 4
    arr[] = {4, 3, 2, 6}
Output:
29
*/
/*
Method 1:
TC-O(N * Log(N)) SC-O(N) :
*/
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long s = 0;

        for (long long i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        while (pq.size() != 1)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            s += x + y;

            pq.push(x + y);
        }

        return s;
    }
};