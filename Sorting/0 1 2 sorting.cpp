#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Input:
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
*/
/*
Method 1:
TC-O(N) SC-O(1) : 2 Traversal. Count number of 0,1,2 and change in 2nd traversal.
*/

/*
Method 2:
TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    void sort012(int a[], int n)
    {
        int lo = 0;
        int hi = n - 1;
        int mid = 0;

        while (mid <= hi)
        {
            switch (a[mid])
            {
            case 0:
                swap(a[lo++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid], a[hi--]);
                break;
            }
        }
    }
};