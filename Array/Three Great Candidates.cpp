#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/three-great-candidates0515/1/

The hiring team aims to find 3 candidates who are great collectively. Each candidate has his or her ability expressed as an integer. 3 candidates are great collectively if product of their abilities is maximum. Given abilities of N candidates in an array arr[], find the maximum collective ability from the given pool of candidates.

Input:
N = 5
Arr[] = {10, 3, 5, 6, 20}
Output: 1200
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/

class Solution
{
public:
    long long maxProduct(int arr[], int n)
    {
        int max_first = INT_MIN, max_second = INT_MIN, max_third = INT_MIN,
            min_first = INT_MAX, min_second = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max_first)
            {
                max_third = max_second;
                max_second = max_first;
                max_first = arr[i];
            }
            else if (arr[i] <= max_first && arr[i] > max_second)
            {
                max_third = max_second;
                max_second = arr[i];
            }
            else if (arr[i] <= max_second && arr[i] > max_third)
            {
                max_third = arr[i];
            }

            if (arr[i] < min_first)
            {
                min_second = min_first;
                min_first = arr[i];
            }
            else if (arr[i] >= min_first && arr[i] < min_second)
            {
                min_second = arr[i];
            }
        }

        return max((long long)min_first * min_second * max_first, (long long)max_first * max_second * max_third);
    }
};