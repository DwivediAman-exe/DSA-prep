#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1/

Given two sorted arrays A and B of size M and N respectively. Each array contains only distinct elements but may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any of the two arrays. We can switch from one array to another array only at the common elements.
Note: Only one repeated value is considered in the valid path sum.

Input:
    M = 5, N = 4
    A[] = {2,3,7,10,12}
    B[] = {1,5,7,8}
Output: 35
Explanation: The path will be 1+5+7+10+12  = 35.


Method 1:
TC-O(N) SC-O(1) :
*/

class Solution
{
public:
    /*You are required to complete this method*/
    int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int res = 0, curr_sum_A = 0, curr_sum_B = 0;
        int i = 0, j = 0;

        while (i < l1 && j < l2)
        {
            if (A[i] < B[j])
            {
                curr_sum_A += A[i++];
            }
            else if (A[i] > B[j])
            {
                curr_sum_B += B[j++];
            }
            else
            {
                res += max(curr_sum_A, curr_sum_B) + A[i];
                i++;
                j++;
                curr_sum_A = curr_sum_B = 0;
            }
        }

        while (i < l1)
        {
            curr_sum_A += A[i++];
        }

        while (j < l2)
        {
            curr_sum_B += B[j++];
        }

        res += max(curr_sum_A, curr_sum_B);

        return res;
    }
};