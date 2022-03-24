#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1/

Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
*/
/*
Method 1:

TC-O(N * Log(N)) SC-O(N) :
*/
class Solution
{
public:
    double median;
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    // Function to insert heap.
    void insertHeap(int &x)
    {
        if (minq.size() == 0 && maxq.size() == 0)
        {
            maxq.push(x);
            median = x;
        }
        else
        {
            if (x < median)
                maxq.push(x);
            else
                minq.push(x);
        }
        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        if (maxq.size() > minq.size() + 1)
        {
            int t = maxq.top();
            maxq.pop();
            minq.push(t);
        }
        else if (minq.size() > maxq.size() + 1)
        {
            int t = minq.top();
            minq.pop();
            maxq.push(t);
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if (maxq.size() == minq.size())
        {
            median = (maxq.top() + minq.top()) / 2.0;
        }
        else if (maxq.size() > minq.size())
            median = maxq.top();
        else
            median = minq.top();
        return median;
    }
};