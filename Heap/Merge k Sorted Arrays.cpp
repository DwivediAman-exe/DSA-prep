#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1/

Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
*/
/*
Method 1:
TC-O(N*k*log(N*k)) SC-O(N*k) : Combine all arrays and apply sorting.
*/

/*
Method 2:
TC-O(N*k*log(k)) SC-O(N*k*log(k)) : Recursively divide arrays into 2 groups and combine in linear time when only 2 are left.
*/

/*
Method 3:
TC-O(N*k*log(k)) SC-O(K) :
*/
struct triplet
{
    int apos, vpos, val;
    triplet(int v, int ap, int vp)
    {
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct comp
{
    bool operator()(const triplet &a, const triplet &b)
    {
        return a.val > b.val;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;
        priority_queue<triplet, vector<triplet>, comp> pq;

        for (int i = 0; i < K; i++)
        {
            triplet t(arr[i][0], 0, i);
            pq.push(t);
        }

        while (!pq.empty())
        {
            triplet temp = pq.top();
            pq.pop();

            res.push_back(temp.val);

            int ap = temp.apos, vp = temp.vpos;
            if (ap + 1 < arr[vp].size())
            {
                triplet t(arr[vp][ap + 1], ap + 1, vp);
                pq.push(t);
            }
        }

        return res;
    }
};