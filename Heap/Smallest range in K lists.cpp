#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/

Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
*/
/*
Method 1:
TC-O(N * K * log(K)) SC-O(k) :
*/
struct triplet
{
    int val, apos, vpos;
    triplet(int v, int ap, int vp)
    {
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct cmp
{
    bool operator()(triplet &t1, triplet &t2)
    {
        return t1.val > t2.val;
    }
};

class Solution
{
public:
    pair<int, int> findSmallestRange(int a[][N], int n, int k)
    {
        int minVal = INT_MAX, maxVal = INT_MIN, range = INT_MAX, rmin = 0, rmax = 0;

        priority_queue<triplet, vector<triplet>, cmp> pq;

        for (int i = 0; i < k; i++)
        {
            triplet t(a[i][0], i, 0);
            pq.push(t);

            maxVal = max(maxVal, a[i][0]);
        }

        while (!pq.empty())
        {

            triplet t = pq.top();
            pq.pop();

            minVal = t.val;

            if (range > maxVal - minVal)
            {
                rmin = minVal;
                rmax = maxVal;
                range = maxVal - minVal;
            }

            int apos = t.apos, vpos = t.vpos;

            if (vpos + 1 >= n)
                break;
            else
            {
                int val = a[apos][vpos + 1];
                triplet temp(val, apos, vpos + 1);

                pq.push(temp);

                maxVal = max(maxVal, val);
            }
        }

        return {rmin, rmax};
    }
};