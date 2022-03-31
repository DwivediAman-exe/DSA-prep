#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1/

Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
*/
/*
Method 1:
TC-O(N^3) SC-O(1) :

Use 3 for loops.
*/

/*
Method 2:
TC-O(N ^ 2) SC-O(1) : Sorting
*/

class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3NumbersUtil(int arr[], int n, int i, int s)
    {
        while (i < n - 1)
        {
            if (arr[i] + arr[n - 1] == s)
                return true;

            else if (arr[i] + arr[n - 1] < s)
            {
                i++;
            }
            else if (arr[i] + arr[n - 1] > s)
            {
                n--;
            }
        }
        return false;
    }
    bool find3Numbers(int arr[], int n, int X)
    {
        // Your Code Here
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if (find3NumbersUtil(arr, n, i + 1, X - arr[i]))
                return true;
        }
        return false;
    }
};

/*
Method 3:
TC-O(N ^ 2) SC-O(N) : Hashing
*/

class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;

            int t1 = X - A[i];

            for (int j = i + 1; j < n; j++)
            {
                int target = t1 - A[j];

                if (st.find(target) != st.end())
                {
                    return true;
                }
                else
                {
                    st.insert(A[j]);
                }
            }
        }

        return false;
    }
};