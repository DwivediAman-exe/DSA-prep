#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/mountain-subarray-problem/1/

We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing. More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exists an integer K, 1 <= K <= N such that,
a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN
You have to process Q queries. In each query you are given two integer L and R, denoting starting and last index of the subarrays respectively.

Input:
    N = 8
    a[] = {2,3,2,4,4,6,3,2}
    Q = 2
    Queries = (0,2), (1,3)
Output:
Yes
No

Method 1:

TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    void preprocess(int a[], int n, vector<int> &left, vector<int> &right)
    {
        int lastincr = 0, firstdecr = n - 1;

        left[0] = 0;
        right[n - 1] = n - 1;

        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i - 1])
                lastincr = i;
            left[i] = lastincr;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1])
                firstdecr = i;
            right[i] = firstdecr;
        }
    }
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q)
    {
        vector<int> left(n), right(n);
        vector<bool> res;

        preprocess(a, n, left, right);

        for (int i = 0; i < q; i++)
        {
            res.push_back((right[queries[i].first] >= left[queries[i].second]));
        }

        return res;
    }
};