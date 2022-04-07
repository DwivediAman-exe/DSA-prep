#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1/

Given two arrays of integers A[] and B[] of size N and M, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Input: N = 6, M = 4
A[] = {4, 1, 2, 1, 1, 2}
B[] = (3, 6, 3, 3)
Output: 1
*/
/*
Method 1:
TC-O(N*Log(N) + M*Log(M)) SC-O(M+N) :
*/

class Solution
{

public:
    int findSwapValues(int A[], int n, int B[], int m)
    {
        sort(A, A + n);
        sort(B, B + m);

        int s1 = accumulate(A, A + n, 0);
        int s2 = accumulate(B, B + m, 0);

        int i = 0, j = 0;

        while ((s1 + B[j] - A[i]) != (s2 + A[i] - B[j]) && (i < n && j < m))
        {

            //  cout<<s1 + B[j] - A[i]<<' '<<s2 + A[i] - B[j]<<endl;
            if ((s1 + B[j] - A[i]) > (s2 + A[i] - B[j]))
                i++;
            else
                j++;
        }

        if ((s1 + B[j] - A[i]) == (s2 + A[i] - B[j]))
            return 1;
        else
            return -1;
    }
};

/*
Method 2:
TC-O(M+N) SC-O(M+N) :
*/

class Solution
{

public:
    int findSwapValues(int A[], int n, int B[], int m)
    {
        int s1 = accumulate(A, A + n, 0);
        int s2 = accumulate(B, B + m, 0);

        unordered_set<int> st(B, B + m);

        if (abs(s2 - s1) % 2)
            return -1;

        for (int i = 0; i < n; i++)
        {
            int x = ((s2 - s1) + 2 * A[i]) / 2;
            if (st.find(x) != st.end())
                return 1;
        }

        return -1;
    }
};