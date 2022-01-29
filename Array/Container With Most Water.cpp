#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1/

Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai). N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0). Find two lines, which together with x-axis forms a container, such that it contains the most water.

Input:
N = 4
a[] = {1,5,4,3}
Output: 6
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/
long long maxArea(long long A[], int len)
{
    long long ans = 0, curr_area = 0, i = 0, j = len - 1;

    while (i < j)
    {
        int dist = j - i;

        curr_area = dist * min(A[i], A[j]);
        ans = max(ans, curr_area);

        if (A[i] < A[j])
            i++;
        else
            j--;
    }

    return ans;
}
