#include <bits/stdc++.h>
using namespace std;
/*
Question Link - Given an array Arr of N positive integers, find K largest elements from the array.  The output elements should be printed in decreasing order.

Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23


Method 1: Sort and print last k elements.
TC-O(N*Log(N)) SC-O(N) :

Method 2: Use Max Heap
TC-O(N + K*Log(N)) SC-O(N) :

Method 3:
TC-O(N + KlogK) SC-O(K+(N-K)*logK) :
*/
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            if (pq.size() < k)
                pq.push(arr[i]);
            else
            {
                if (pq.top() < arr[i])
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }

        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};