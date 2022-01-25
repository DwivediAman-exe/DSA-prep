#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1

Given an array arr[] of N weights. Find the least weight capacity of a boat to ship all weights within D days.
Note: You have to load weights on the ship in the given order.

Input:
    N = 3
    arr[] = {1, 2, 1}
    D = 2
Output:
3
*/

/*
Method 1:
TC-O(N*log(Sum of weights - max(list of weights)) SC-O(1) :
*/
class Solution
{
public:
    bool isValid(int arr[], int n, int D, int cap)
    {
        int days = 1, currwt = 0;

        for (int i = 0; i < n; i++)
        {
            currwt += arr[i];

            if (currwt > cap)
            {
                days++;
                currwt = arr[i];
            }

            if (days > D)
                return false;
        }

        return true;
    }

    int leastWeightCapacity(int arr[], int N, int D)
    {

        int sum = 0, maxwt = 0, res = -1;

        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            maxwt = max(maxwt, arr[i]);
        }

        int start = maxwt, end = sum;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (isValid(arr, N, D, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return res;
    }
};