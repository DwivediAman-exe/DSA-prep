#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1/

Find out the maximum sub-array of non negative numbers from an array.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE 1: If there is a tie, then compare with segment's length and return segment which has maximum length.
NOTE 2: If there is still a tie, then return the segment with minimum starting index.

Input:
N = 3
A[] = {1, 2, 3}
Output: 1 2 3

Method 1:
TC-O(N) SC-O(1) :
*/

class Solution
{
public:
    vector<int> findSubarray(int arr[], int n)
    {
        vector<int> res;
        long long mx = 0, curr = 0, s = 0, e = 0, curr_s = 0, curr_e = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                curr += arr[i];
                curr_e = i;
            }
            else
            {
                if ((mx < curr) || (mx == curr && curr_s - curr_e > s - e))
                {
                    s = curr_s;
                    e = curr_e;
                    mx = curr;
                }

                curr = 0;
                curr_s = i + 1;
            }
        }

        if ((mx < curr) || (mx == curr && curr_s - curr_e > s - e))
        {
            s = curr_s;
            e = curr_e;
            mx = curr;
        }

        for (int i = s; i <= e; i++)
            res.push_back(arr[i]);

        if (res.size() == 0)
            return {-1};

        return res;
    }
};