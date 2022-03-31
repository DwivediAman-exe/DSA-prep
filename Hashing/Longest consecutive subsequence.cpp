#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1/

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
*/
/*
Method 1:
TC-O(N * Log(N)) SC-O(1) :  Sort the array and find longest consecutive subarray.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> st(arr, arr + N);
        int res = 1;

        for (int i = 0; i < N; i++)
        {
            if (st.find(arr[i] - 1) == st.end())
            {
                int num = arr[i] + 1, curr = 1;

                while (st.find(num) != st.end())
                {
                    num++;
                    curr++;
                }

                res = max(res, curr);
            }
        }

        return res;
    }
};